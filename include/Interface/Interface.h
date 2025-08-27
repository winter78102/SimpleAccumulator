

#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>
#include <File/File.h>
#include <Consol/Consol.h>
#include <numeric>


class Interface {
public:
    Interface() = default;

    void SelectStage();

    void Calculate();

private:
    int _SelectButton;
    File _File;
    Consol _Consol;


};

#endif //INTERFACE_H
