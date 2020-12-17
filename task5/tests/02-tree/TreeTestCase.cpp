//
// Created by akhtyamovpavel on 5/1/20.
//

#include "TreeTestCase.h"
#include "Tree.h"

#include <iostream>

#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <string>
#include <fstream>

namespace fs = boost::filesystem;


TEST_F(TreeTestCase, test1)
{
    fs::path temp_path = fs::current_path();
    temp_path /= "temp";
    std::string temp = temp_path.string(); 
    ASSERT_TRUE(GetTree(temp, false).is_dir);
    ASSERT_NO_THROW(GetTree(temp, false));
    ASSERT_NO_THROW(GetTree(temp, true));
    ASSERT_GE(GetTree(temp, true).children.size(), 0);
    ASSERT_EQ(GetTree(temp, false).children.size(), 1);
    ASSERT_THROW(GetTree(temp + "/non-existing-file.txt", false), std::invalid_argument);
    ASSERT_THROW(GetTree(temp + "/klasdasdasd.txt", true), std::invalid_argument);
    FileNode f1 = GetTree(temp, false);
    FileNode f2 = GetTree(temp, false);
    FileNode f3 = GetTree(".", false);
    ASSERT_TRUE(f1 == f2);
    ASSERT_FALSE(f1 == f3);
}