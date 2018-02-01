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

#include "../models/result.hpp"
#include "../benchmakr_common.hpp"

////////////////////////////////////////////////////////////////////////////////////
// Begin STL INCLUDES                                                             //
////////////////////////////////////////////////////////////////////////////////////
#include <cstdint>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
////////////////////////////////////////////////////////////////////////////////////
// End STL INCLUDES                                                               //
////////////////////////////////////////////////////////////////////////////////////

namespace rlnc_benchmark_suit
{
namespace encoder
{
    /// g = Generation size
    /// k = symbol size
    /// r = redunancy symbols
    /// systematic = Is systematic on or off
    template<typename Code>
    rlnc_benchmark_suit::models::result block_encoder_benchmark(uint32_t g,
                                                        uint32_t k, uint32_t r,
                                                        bool systematic)
    {
        // Seed the random generator
        srand(static_cast<uint32_t>(time(0)));

        // Construct the RLNC code factory
        typename Code::factory factory(g, k);
        auto encoder = factory.build();

        if (!systematic)
        {
            encoder->set_systematic_off();
        }

        std::vector<std::vector<uint8_t>> payloads(g,
                                                   std::vector<uint8_t>(
                                                       encoder->payload_size()));

        // Create a vector which can contain all data within a generation
        std::vector<uint8_t> data(encoder->block_size());

        // Fill the data vector with random data
        std::generate(data.begin(), data.end(), rand);

        // Preload the block encoder with all symbols
        encoder->set_const_symbols(storage::storage(data));

        ////////////////////////////////////////////////////////////////////////
        // Start timer                                                        //
        ////////////////////////////////////////////////////////////////////////
        auto start = std::chrono::high_resolution_clock::now();

        for (auto& payload : payloads)
        {
            encoder->write_payload(payload.data()); // Encode symbols
        }

        for (uint32_t i = 0; i < r; ++i)
        {
            encoder->write_payload(
                payloads[rlnc_benchmark_suit::random_index(payloads.size())].data());
        }

        ////////////////////////////////////////////////////////////////////////
        // Stop timer                                                         //
        ////////////////////////////////////////////////////////////////////////
        auto end = std::chrono::high_resolution_clock::now();

        auto s =  std::chrono::duration_cast<std::chrono::microseconds>(
            start.time_since_epoch());


        auto e = std::chrono::duration_cast<std::chrono::microseconds>(
            end.time_since_epoch());
        return rlnc_benchmark_suit::models::result(s, e, generation_size, symbol_size);


    }

    template<typename Code>
    std::vector<rlnc_benchmark_suit::models::result> run_benchmark(
        uint32_t itterations, uint32_t generation_size,
        uint32_t symbol_size, uint32_t redundancy,
        bool systematic)
    {

        std::cout << "Experiment Started " << std::endl;

        std::vector<result> results;

        for (uint32_t i = 0; i < itterations; ++i) {
            results.push_back(encoder_benchmark<Code>(generation_size,
                                                      symbol_size, redundancy,
                                                      systematic));
        }
        std::cout << "Experiment Finished" << std::endl;
        return results;
    }
}
}
