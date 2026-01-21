#include <gtest/gtest.h>

#include "../inc/Model.hpp"
#include "../inc/Inwentarz.hpp"
#include "../inc/DAO.hpp"

namespace {
  int GetMeaningOfLife() {  return 42; }
}

TEST(TestTopic, TrivialEquality) {
  EXPECT_EQ(GetMeaningOfLife(), 42);
}

TEST(TestTopic, MoreEqualityTests) {
  ASSERT_EQ(GetMeaningOfLife(), 0) << "Oh no, a mistake!";
  EXPECT_FLOAT_EQ(23.23F, 23.23F);
}

TEST(TestTopic, ExternalTest) {
  Model::DAO dao;
  Model::Inwentarz inwentarz(&dao);

  Model::Model model(&inwentarz, &dao);

  EXPECT_EQ(model.znalezienieKursu(0), "");
  EXPECT_EQ(model.znalezienieKursu(1), "1;1,2;10:00,11:00");
  EXPECT_EQ(model.znalezienieKursu(6), "");
}