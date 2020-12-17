//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <string>
#include <fstream>

namespace fs = boost::filesystem;


class TreeTestCase : public ::testing::Test {
protected:
    
    virtual void SetUp() {
        fs::path temp_path = fs::current_path();
        temp_path /= "temp/file.txt";
        fs::create_directories(temp_path.parent_path());
        std::ofstream ofs1(temp_path.string());
        ofs1 << "text\n";
        ofs1.close();
    }

    virtual void TearDown() {
        fs::path temp_path = fs::current_path();
        temp_path /= "temp";
        fs::remove_all(temp_path);
    }
};

