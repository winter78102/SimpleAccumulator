//
// Created by Bahar on 9/9/2025.
//

#ifndef MULTITHREAD_CLIENT_H
#define MULTITHREAD_CLIENT_H

#include <Parser/File/File.h>
#include <Parser/Consol/Consol.h>
#include <Operator/Accumulator/Accumulator.h>
#include <Operator/Subtractor/Subtractor.h>
#include <Operator/Multiplier/Multiplier.h>
#include <Operator/Divider/Divider.h>
#include <ThreadManager/ThreadMnager.h>

class Client {
public:
    void SelectReader(int Selector);

    void SelectOperator(char Sign);

    void SelectThreadNumber();


private:
    File _File;
    Consol _Consol;
    std::vector<double> _Storage;
    Accumulator _Accum;
    Subtractor _Subtract;
    Multiplier _Multiply;
    Divider _Divider;
    ThreadManager _ThreadManage;

};

#endif //MULTITHREAD_CLIENT_H
