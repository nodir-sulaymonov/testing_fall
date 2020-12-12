//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>


TEST_F(LeapTestCase, test1)
{
    ASSERT_THROW(IsLeap(0), std::invalid_argument);
    ASSERT_THROW(IsLeap(-5), std::invalid_argument);
    ASSERT_FALSE(IsLeap(1));
    ASSERT_TRUE(IsLeap(400));
    ASSERT_TRUE(IsLeap(800));
    ASSERT_FALSE(IsLeap(1993));
    ASSERT_FALSE(IsLeap(2100));
    ASSERT_FALSE(IsLeap(2001));
    ASSERT_TRUE(IsLeap(2020));
    ASSERT_TRUE(IsLeap(1996));
}