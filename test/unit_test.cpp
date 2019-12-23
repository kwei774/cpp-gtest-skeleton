#include "unit.h"

#include "gtest/gtest.h"

namespace {

// The fixture for testing class Foo.
class UnitTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.

  UnitTest() {
     // You can do set-up work for each test here.
  }

  ~UnitTest() override {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  void SetUp() override {
  }

  void TearDown() override {
  }

};

// Tests that the Foo::Bar() method does Abc.
TEST_F(UnitTest, AnswerReturns42) {
  EXPECT_EQ(answer(), 42);
}

} 

GTEST_API_ int main(int argc, char **argv) {
    printf("Running main() from main.cc\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}