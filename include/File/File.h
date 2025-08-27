//
// Created by Bahar on 8/27/2025.
//

#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <Reader/Reader.h>
class File:public  Reader{
public:
  void GetString()override;
  void SetFileAddr();

private:
    std::string _FileAddr;

};
#endif //FILE_H
