

#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>
#include <File/File.h>
#include <Consol/Consol.h>
#include "ThreadManager//ThreadMnager.h"
#include <numeric>


class Interface {
public:
    Interface() = default;

    void SelectStage();

    void SetOperatorSymbol();

    void Calculate();

private:
    int _SelectButton;
    std::string _Operator;
    File _File;
    Consol _Consol;
    ThreadManager _ThreadManager;


};

#endif //INTERFACE_H
