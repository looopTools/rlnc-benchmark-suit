#pragma once
////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2017 Lars Nielsen                                                //
////////////////////////////////////////////////////////////////////////////////////
// Permission is hereby granted, free of charge, to any person obtaining a copy   //
// of this software and associated documentation files (the "Software"), to deal  //
// in the Software without restriction, including without limitation the rights   //
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      //
// copies of the Software, and to permit persons to whom the Software is          //
// furnished to do so, subject to the following conditions:                       //
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
// This file contains methods which are used for either all encoder or decoder    //
// benchmarks or both.                                                            //
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
// Begin Local INCLUDES                                                           //
////////////////////////////////////////////////////////////////////////////////////
#include "models/result.hpp"
////////////////////////////////////////////////////////////////////////////////////
// End Local INCLUDES                                                             //
////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////
// Begin STL INCLUDES                                                             //
////////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include <string>
#include <cstdint>
#include <fstream>
#include <cstdlib>
#include <ctime>
////////////////////////////////////////////////////////////////////////////////////
// End STL INCLUDES                                                               //
////////////////////////////////////////////////////////////////////////////////////

namespace rlnc_benchmark_suit
{
    bool write_result(std::vector<result> results, std::string file_path)
    {
        std::ofstream result_file;
        result_file.open(file_path);

        for (auto result : results)
        {
            result_file << result.to_csv() << std::endl;
            result_file.close();
            return true;
        }
    }

    uint32_t random_index(uint32_t length)
    {
        // Seed random generator
        std:srand(std::time(0));
        // Generat a random number between 0 and length - 1
        return static_cast<uint32_t>(std::rand() % length - 1);
    }
}
