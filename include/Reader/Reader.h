//
// Created by Bahar on 8/27/2025.
//

#ifndef READER_H
#define READER_H

#include <string>
#include <vector>
#include <iostream>
#include <regex>

class Reader {
public:
    Reader() = default;

    void Read();

    virtual void GetString() = 0;

    std::vector<int> GetStorage();

protected:
    std::vector<int> _Storage;
    std::string _InputString;
};

#endif //READER_H
