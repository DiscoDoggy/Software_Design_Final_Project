#include "gtest/gtest.h"
#include "library_test.hpp"
#include "librarySystem.hpp"
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
