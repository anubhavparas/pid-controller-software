/** Copyright 2021 Anubhav Paras  */

#include <gtest/gtest.h>
#include <lib.hpp>

TEST(dummy_test, should_pass) {
  dummy();
  EXPECT_EQ(1, 1);
}
