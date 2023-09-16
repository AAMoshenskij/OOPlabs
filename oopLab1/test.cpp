#include <gtest/gtest.h>
#include "func.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(check_palindrom("add a")==false);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(check_palindrom("aaabbb")==false);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(check_palindrom("abba")==true);
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(check_palindrom("1221")==true);
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(check_palindrom("1234")==false);
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(check_palindrom("a")==true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
