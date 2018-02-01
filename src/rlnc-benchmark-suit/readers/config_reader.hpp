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
// This file contains functions for reading config data from a file               //
////////////////////////////////////////////////////////////////////////////////////
#include "../models/config.hpp"
////////////////////////////////////////////////////////////////////////////////////
// Begin STL INCLUDES                                                             //
////////////////////////////////////////////////////////////////////////////////////
#include <cstdint>
#include <string>
#include <sstream>
#include <fstream>
////////////////////////////////////////////////////////////////////////////////////
// End STL INCLUDES                                                               //
////////////////////////////////////////////////////////////////////////////////////

namspace rlnc_benchmark_suit
{
namspace readers
{

    int extract_config(std::string line)
    {
        std::stringstream ss;
        ss.str(line);
        std::string temp;
        int setting = 0;

        while(std::getline(ss, temp, ':'))
        {
            if (setting != 0)
            {
                setting = std::stoi(temp);
                break;
            }
            ++setting;
        }
        return setting;
    }

    void set_parameter(config* conf, int setting, int line_number)
    {
        if (line_number == 0)
        {
            conf->set_generation_size(setting);
        } else if (line_number == 1)
        {
            conf->set_symbol_size(setting);
        } else if (line_number == 2)
        {
            conf->set_redundancy(setting);
        } else if (line_number == 3)
        {
            conf->set_filed(setting);
        } else if (line_number == 4)
        {
            conf->set_iterations(setting)
        } else
        {
            if (setting == 1)
            {
                conf->set_is_systematic(true);
            } else
            {
                conf->set_is_systematic(false);
            }
        }

    }

    config read_config(std::string file_path)
    {
        std::ifstram file(file_path);
        std::string line;
        int line_number = 0;

        auto conf = config();

        while (std:getline(file, line))
        {
            set_parameter(&conf, extract_config(line), line_number);
            ++line_number;
        }
        return conf;
    }

}
}
