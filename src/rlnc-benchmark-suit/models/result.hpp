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
// Result: This class model the result which can be produced by the benchmark     //
//         suit                                                                   //
// Termnology:                                                                    //
//         g: generation size                                                     //
//         k: symbol size                                                         //
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
// Begin STL INCLUDES                                                             //
////////////////////////////////////////////////////////////////////////////////////
#include <cstdint>
#include <chrono>
#include <sstream>
#include <string>
////////////////////////////////////////////////////////////////////////////////////
// End STL INCLUDES                                                               //
////////////////////////////////////////////////////////////////////////////////////

namespace rlnc_benchmark_suit
{
namespace model
{
class result
{
public:

    result(std::chrono::microseconds start, std::chrono::microseconds end,
           uint32_t g, uint32_t k) : m_start(start), m_end(end), m_g(g), m_k(k)
    {
        m_data_size = g * k;
    }

    uint64_t latency()
    {
        return static_cast<uint64_t>(m_end.count() - m_start.count());
    }

    double throughput()
    {
        return static_cast<double>(m_data_size / this->latency());
    }

    /// method: to_csv
    /// @ret std::string
    /// Returns the result in as a comma seperated structure on the
    /// following format:
    /// START,END,DATA_SIZE,K,G,THROUGHPUT,LATENCY
    std::string to_csv()
    {
        std::stringstream ss;
        ss << m_start.count() << ","
           << m_end.count() << ","
           << m_data_size << ","
           << m_k << ","
           << m_g << ","
           << throughput() << ","
           << latency();
        return ss.string();
    }

private:
    uint32_t m_data_size;
    uint32_t m_g;
    uint32_t m_k;
    std::chrono::microseconds m_start;
    std::chrono::microseconds m_end;

}
}
}
