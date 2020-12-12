//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"
#include <climits>


TEST_F(AddTestCase, test1)
{
    ASSERT_EQ(0, Add(0, 0));
    ASSERT_EQ(-10, Add(20, -30));
    ASSERT_EQ(85, Add(15, 70));
    ASSERT_EQ(-40, Add(-20, -20));
    ASSERT_EQ(-1, Add(INT_MAX, INT_MIN));
}