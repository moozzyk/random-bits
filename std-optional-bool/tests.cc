#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

TEST(stdOptionalBoolTest, IncorrectTest) {
  ASSERT_TRUE(std::optional<bool>{false});
}

TEST(stdOptionalBoolTest, CorrectTest) {
  EXPECT_EQ(std::optional<bool>{false}, true);
  EXPECT_TRUE(std::optional<bool>{false}.value());
}
