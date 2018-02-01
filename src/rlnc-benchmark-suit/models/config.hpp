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
// Config: This class model the configurations which can be used with the         //
//         benchmark suit                                                         //
// Termnology:                                                                    //
//         g: generation size                                                     //
//         k: symbol size                                                         //
//         r: redundancy symbols                                                  //
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
// Begin STL INCLUDES                                                             //
////////////////////////////////////////////////////////////////////////////////////
#include <cstdint>
////////////////////////////////////////////////////////////////////////////////////
// End STL INCLUDES                                                               //
////////////////////////////////////////////////////////////////////////////////////

namespace rlnc_benchmark_suit
{
namespace model
{
class config
{
public:
    config()
    {}

    void set_symbol_size(uint32_t k)
    {
        m_k = k;
    }

    uint32_t symbol_size()
    {
        return m_k
    }

    void set_generation_size(uint32_t g)
    {
        m_g = g;
    }

    uint32_t generation_size()
    {
        return g;
    }

    void set_iterations(uint32_t iterations)
    {
        m_iterations = iterations;
    }

    uint32_t iterations()
    {
        return m_iterations;
    }

    void set_field(uint16 filed)
    {
        m_field = field;
    }

    uint16_t field()
    {
        return m_field;
    }

    void set_is_systematic(bool is_systematic)
    {
        m_is_systematic = is_systematic;
    }

    bool is_systematic()
    {
        return is_systematic;
    }

private:
    uint32_t m_k;
    uint32_t m_g;
    uint32_t m_r;
    uint32_t m_iterations;
    uint16_t m_field;
    bool m_is_systematic;

};
}
}
