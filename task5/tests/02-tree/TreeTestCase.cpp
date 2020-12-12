//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"

#include <iostream>

TEST_F(TreeTestCase, test1)
{
    ASSERT_TRUE(GetTree(".", false).is_dir);
    ASSERT_NO_THROW(GetTree("..", false));
    ASSERT_NO_THROW(GetTree("..", true));
    ASSERT_GE(GetTree("..", true).children.size(), 0);
    ASSERT_THROW(GetTree("non-existing-file.txt", false), std::invalid_argument);
    ASSERT_THROW(GetTree("klasdasdasd.txt", true), std::invalid_argument);
    FileNode f1 = GetTree(".", true);
    FileNode f2 = GetTree(".", true);
    ASSERT_TRUE(f1 == f2);
}