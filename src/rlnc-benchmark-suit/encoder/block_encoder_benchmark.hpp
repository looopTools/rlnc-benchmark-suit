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


#include "../result.hpp"

// STDLIB includes:
#include <cstdint>

namespace rlnc_benchmark_suit
{
namespace encoder
{
    /// g = Generation size
    /// k = symbol size
    /// r = redunancy symbols
    /// systematic = Is systematic on or off
    template<typename Code>
    rlnc_benchmark_suit::result block_encoder_benchmark(uint32_t g,
                                                        uint32_t k, uint32_t r,
                                                        bool systematic)
    {
        // Seed the random generator
        srand(static_cast<uint32_t>(time(0)));


    }
}
}
