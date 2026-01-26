#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../inc/ModyfikowanieRozkladuJazdy.hpp"
#include "TestModyfikowanieRozkladuJazdy.hpp"

#include <string>
#include <vector>

using namespace std;
using namespace testing;

class ModyfikowanieRozkladuJazdyTest : public ::testing::Test {
protected:
    StrictMock<Model::MockAbsModel> mockModel;
    
    Kontroler::ModyfikowanieRozkladuJazdy kontroler;

    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(ModyfikowanieRozkladuJazdyTest, ModyfikacjaKursu_PoprawneDane_ZapisujeZmiany) {
    int idKursu = 1;
    string daneWejsciowe = "1;10;08:00;99";
    string oczekiwaneDaneWyjsciowe = "1;10,3,5,6,21;08:00,10:00,10:15,10:30,10:45;99";

    EXPECT_CALL(mockModel, znalezienieKursu(idKursu))
        .WillOnce(Return(daneWejsciowe));

    EXPECT_CALL(mockModel, modyfikowanieKursu(oczekiwaneDaneWyjsciowe))
        .Times(1);

    kontroler.modyfikowanieRozkladuJazdy(&mockModel, idKursu);

}

TEST_F(ModyfikowanieRozkladuJazdyTest, ModyfikacjaKursu_KursNieIstnieje_RzucaWyjatek) {
    int idKursu = 999;
    
    EXPECT_CALL(mockModel, znalezienieKursu(idKursu))
        .WillOnce(Return(""));

    EXPECT_CALL(mockModel, modyfikowanieKursu(_))
        .Times(0);

    try {
        kontroler.modyfikowanieRozkladuJazdy(&mockModel, idKursu);
        FAIL() << "Oczekiwano wyjątku, ale nic nie rzucono.";
    } catch(const char* msg) {
        EXPECT_STREQ(msg, "Brak Kursu o podanym ID");
    } catch(...) {
        FAIL() << "Rzucono nieoczekiwany typ wyjątku.";
    }

}

TEST_F(ModyfikowanieRozkladuJazdyTest, ModyfikacjaKursu_BlednyFormatDanych_RzucaWyjatek) {
    int idKursu = 2;
    string zlyFormat = "1;TylkoJednaSekcja"; 

    EXPECT_CALL(mockModel, znalezienieKursu(idKursu))
        .WillOnce(Return(zlyFormat));

    EXPECT_CALL(mockModel, modyfikowanieKursu(_))
        .Times(0);

    try {
        kontroler.modyfikowanieRozkladuJazdy(&mockModel, idKursu);
        FAIL() << "Oczekiwano wyjątku dla błędnego formatu.";
    } catch(const char* msg) {
        EXPECT_STREQ(msg, "Invalid data format");
    }
}

TEST_F(ModyfikowanieRozkladuJazdyTest, ModyfikacjaKursu_WeryfikacjaKolejnosci) {
    InSequence s;
    
    string input = "5;1;12:00;Kierowca1";
    string expected = "5;1,3,5,6,21;12:00,10:00,10:15,10:30,10:45;Kierowca1";

    EXPECT_CALL(mockModel, znalezienieKursu(5))
        .WillOnce(Return(input));

    EXPECT_CALL(mockModel, modyfikowanieKursu(expected))
        .Times(1);

    kontroler.modyfikowanieRozkladuJazdy(&mockModel, 5);

}
