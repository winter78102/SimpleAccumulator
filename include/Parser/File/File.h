//
// Created by Bahar on 8/27/2025.
//

#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <Parser/Parser.h>

class File : public Parser {
public:
    void GetString() override;

    void SetFileAddr();

private:
    std::string _FileAddr;

};

#endif //FILE_H
