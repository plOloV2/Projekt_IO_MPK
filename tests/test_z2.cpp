#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../inc/ModyfikowanieRozkladuJazdy.hpp"
#include "test_z2.hpp"

#include <string>
#include <vector>

using namespace std;
using namespace testing;

// Fixture testowy - przygotowuje środowisko dla każdego testu
class ModyfikowanieRozkladuJazdyTest : public ::testing::Test {
protected:
    // 1. Symulacja obiektu zależnego (Mock)
    StrictMock<Model::MockAbsModel> mockModel;
    
    // Obiekt testowany
    Kontroler::ModyfikowanieRozkladuJazdy kontroler;

    void SetUp() override {
    }

    void TearDown() override {
    }
};

/**
 * Test scenariusza pozytywnego (Happy Path).
 * Sprawdza, czy kontroler pobiera kurs, modyfikuje go (dodaje przystanki i czasy)
 * i zapisuje z powrotem w modelu.
 */
TEST_F(ModyfikowanieRozkladuJazdyTest, ModyfikacjaKursu_PoprawneDane_ZapisujeZmiany) {
    // --- GIVEN (Konfiguracja symulacji) ---
    int idKursu = 1;
    // Format danych z DAO: ID;Przystanki;Czasy;IdKierowcy
    // Przykładowy stan początkowy: ID=1, Przystanek=10, Czas=08:00, Kierowca=99
    string daneWejsciowe = "1;10;08:00;99"; 

    // Oczekujemy, że kontroler doda sztywne dane z kodu:
    // Przystanki dodawane w kodzie: 3, 5, 6, 21. Wynik: 10,3,5,6,21
    // Czasy dodawane w kodzie: 10:00, 10:15, 10:30, 10:45. Wynik: 08:00,10:00,10:15,10:30,10:45
    string oczekiwaneDaneWyjsciowe = "1;10,3,5,6,21;08:00,10:00,10:15,10:30,10:45;99";

    // 1. Określamy zachowanie mocka: gdy ktoś zapyta o kurs ID=1, zwróć daneWejsciowe.
    EXPECT_CALL(mockModel, znalezienieKursu(idKursu))
        .WillOnce(Return(daneWejsciowe));

    // 2. Określamy oczekiwanie: metoda modyfikowanieKursu musi być wywołana dokładnie raz
    // z argumentem równym oczekiwaneDaneWyjsciowe.
    EXPECT_CALL(mockModel, modyfikowanieKursu(oczekiwaneDaneWyjsciowe))
        .Times(1);

    // --- WHEN (Wykonanie testowanej operacji) ---
    // Wstrzykujemy symulację (wskaźnik do mockModel) do metody kontrolera
    kontroler.modyfikowanieRozkladuJazdy(&mockModel, idKursu);

    // --- THEN (Weryfikacja) ---
    // Weryfikacja następuje automatycznie przez weryfikację asercji EXPECT_CALL przy niszczeniu mocka.
}

/**
 * Test scenariusza: Brak kursu w bazie.
 * Sprawdza, czy metoda rzuca wyjątek, gdy model zwróci pusty ciąg znaków,
 * i upewnia się, że nie próbujemy wtedy niczego zapisywać.
 */
TEST_F(ModyfikowanieRozkladuJazdyTest, ModyfikacjaKursu_KursNieIstnieje_RzucaWyjatek) {
    // --- GIVEN ---
    int idKursu = 999;
    
    // Model zwraca pusty string, co oznacza brak kursu
    EXPECT_CALL(mockModel, znalezienieKursu(idKursu))
        .WillOnce(Return(""));

    // Upewniamy się, że metoda modyfikująca NIGDY nie zostanie wywołana
    EXPECT_CALL(mockModel, modyfikowanieKursu(_))
        .Times(0);

    // --- WHEN & THEN ---
    // Sprawdzamy czy leci wyjątek typu const char* (zgodnie z kodem: throw "Brak Kursu...")
    try {
        kontroler.modyfikowanieRozkladuJazdy(&mockModel, idKursu);
        FAIL() << "Oczekiwano wyjątku, ale nic nie rzucono.";
    } catch(const char* msg) {
        EXPECT_STREQ(msg, "Brak Kursu o podanym ID");
    } catch(...) {
        FAIL() << "Rzucono nieoczekiwany typ wyjątku.";
    }
}

/**
 * Test scenariusza: Nieprawidłowy format danych.
 * Sprawdza zachowanie, gdy dane z modelu są uszkodzone (np. brak średników).
 */
TEST_F(ModyfikowanieRozkladuJazdyTest, ModyfikacjaKursu_BlednyFormatDanych_RzucaWyjatek) {
    // --- GIVEN ---
    int idKursu = 2;
    // String nie zawiera wystarczającej liczby sekcji oddzielonych średnikami
    string zlyFormat = "1;TylkoJednaSekcja"; 

    EXPECT_CALL(mockModel, znalezienieKursu(idKursu))
        .WillOnce(Return(zlyFormat));

    // Nie powinno dojść do zapisu
    EXPECT_CALL(mockModel, modyfikowanieKursu(_))
        .Times(0);

    // --- WHEN & THEN ---
    try {
        kontroler.modyfikowanieRozkladuJazdy(&mockModel, idKursu);
        FAIL() << "Oczekiwano wyjątku dla błędnego formatu.";
    } catch(const char* msg) {
        EXPECT_STREQ(msg, "Invalid data format");
    }
}

/**
 * Test z użyciem kolejności wywołań (InSequence).
 * Sprawdza dokładnie przepływ sterowania.
 */
TEST_F(ModyfikowanieRozkladuJazdyTest, ModyfikacjaKursu_WeryfikacjaKolejnosci) {
    // --- GIVEN ---
    InSequence s; // Wymusza kolejność oczekiwań zdefiniowanych poniżej
    
    string input = "5;1;12:00;Kierowca1";
    // Po dodaniu 4 przystanków i 4 czasów przez kontroler
    string expected = "5;1,3,5,6,21;12:00,10:00,10:15,10:30,10:45;Kierowca1";

    // Krok 1: Pobranie
    EXPECT_CALL(mockModel, znalezienieKursu(5))
        .WillOnce(Return(input));

    // Krok 2: Zapis (musi nastąpić PO pobraniu)
    EXPECT_CALL(mockModel, modyfikowanieKursu(expected))
        .Times(1);

    // --- WHEN ---
    kontroler.modyfikowanieRozkladuJazdy(&mockModel, 5);
}