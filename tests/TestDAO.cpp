#include <gtest/gtest.h>

#include "../inc/DAO.hpp"

using namespace Model;

class DAOTest : public ::testing::Test {
protected:
    DAO* dao;

    void SetUp() override {
        dao = new DAO();
    }

    void TearDown() override {
        delete dao;
    }
};

TEST_F(DAOTest, EdytujKierowce) {
    ASSERT_EQ(dao->znajdzKurs(0), "Brak");
    ASSERT_EQ(dao->znajdzKurs(1), "1;1,2;10:00,11:00;2");
    ASSERT_EQ(dao->znajdzKurs(6), "Brak");
}