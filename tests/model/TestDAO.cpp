#include <gtest/gtest.h>

#include "../inc/DAO.hpp"

using namespace Model;

enum class Zestaw { RIGHT, WRONG };

class DAOTest : public ::testing::TestWithParam<std::tuple<Zestaw, std::string, int>> {
protected:
    DAO* dao;

    void SetUp() override {
        dao = new DAO();
    }

    void TearDown() override {
        delete dao;
    }
};

INSTANTIATE_TEST_SUITE_P(
    EdytowaneKursyPoprawne,
    DAOTest,
    ::testing::Values(
        std::make_tuple(Zestaw::WRONG, "0;1,2;10:00,11:00", 0),
        std::make_tuple(Zestaw::RIGHT, "1;1,2;10:00,11:00", 1),
        std::make_tuple(Zestaw::RIGHT, "2;1,2;10:00,11:00;4", 2),
        std::make_tuple(Zestaw::RIGHT, "3;1,2;10:00,11:00,3", 3),
        std::make_tuple(Zestaw::RIGHT, "4;1,2;10:00,11:00", 4),
        std::make_tuple(Zestaw::RIGHT, "5;1,2;10:00,11:00,5", 5),
        std::make_tuple(Zestaw::WRONG, "6;1,2;10:00,11:00,5", 6)
    )
);

TEST_F(DAOTest, ZnalezienieKursuZPoprawnymID) {
    for(int i = 1; i < 6; i++){
        ASSERT_NE(dao->znajdzKurs(i), "Brak");
    }
}

TEST_F(DAOTest, ZnalezienieKursuZBlednymID) {
    ASSERT_EQ(dao->znajdzKurs(0), "Brak");
    ASSERT_EQ(dao->znajdzKurs(6), "Brak");
}

TEST_F(DAOTest, ZnalezienieKursowZPoprawnymIDPrzystanku) {
    for(int i = 1; i < 6; i++){
        ASSERT_GT(dao->znajdzKursy(i).size(), 0);
    }
}

TEST_F(DAOTest, ZnalezienieKursowZBlednymIDPrzystanku) {
    ASSERT_EQ(dao->znajdzKursy(0).size(), 0);
    ASSERT_EQ(dao->znajdzKursy(6).size(), 0);
}

TEST_F(DAOTest, ZnalezienieKierowcyZPoprawnymID) {
    for(int i = 1; i < 6; i++){
        ASSERT_NE(dao->znajdzKierowce(i), "Brak");
    }
}

TEST_F(DAOTest, ZnalezienieKierowcyZBlednymID) {
    ASSERT_EQ(dao->znajdzKierowce(0), "Brak");
    ASSERT_EQ(dao->znajdzKierowce(6), "Brak");
}

TEST_F(DAOTest, ZnalezienieKierowcowZPoprawnymIDKursu) {
    for(int i = 1; i < 6; i++){
        ASSERT_GE(dao->znajdzKierowcow(i).size(), 0);
        ASSERT_LE(dao->znajdzKierowcow(i).size(), 1);
    }
}

TEST_F(DAOTest, ZnalezienieKierowcowZBlednymIDKursu) {
    ASSERT_EQ(dao->znajdzKierowcow(0).size(), 0);
    ASSERT_EQ(dao->znajdzKierowcow(6).size(), 0);
}

TEST_P(DAOTest, EdycjaKursuOPoprawnymID){
    if (std::get<0>(GetParam()) != Zestaw::RIGHT) {
        GTEST_SKIP();
    }
    dao->edytujKurs(std::get<1>(GetParam()));
    ASSERT_EQ(dao->znajdzKurs(std::get<2>(GetParam())), std::get<1>(GetParam()));
}

TEST_P(DAOTest, EdycjaKursuOBlednymID){
    if (std::get<0>(GetParam()) != Zestaw::WRONG) {
        GTEST_SKIP();
    }

    dao->edytujKurs(std::get<1>(GetParam()));
    ASSERT_EQ(dao->znajdzKurs(std::get<2>(GetParam())), "Brak");
}