#include "gtest/gtest.h"

#include "PhoneBook.hpp"

TEST(utils, run)
{
  PhoneBook phoneBook;
  testing::internal::CaptureStdout();
  phoneBook.run();
  EXPECT_STREQ("> ", testing::internal::GetCapturedStdout().c_str());
}
