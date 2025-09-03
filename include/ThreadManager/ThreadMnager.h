
#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <iostream>
#include <Operator/Operator.h>
#include <Accumulator/Accumulator.h>
#include <Subtractor/Subtractor.h>
#include <Multiplier/Multiplier.h>
#include <Divider/Divider.h>
#include <algorithm>
#include <memory>
#include <vector>
#include <functional>
#include <thread>
#include <condition_variable>


class ThreadManager {
public:
    int PossibleNumber();

    void SetThreadNumber(const std::vector<double> &Storage);

    void SetInputSymbol(char Symbol);

    void FillThreads(const std::vector<double> &Storage);


private:

    int _ThreadNumber;
    std::vector<Operator> _TaskVector;
    char _InputSymbol;
    Accumulator _Accum;
    Subtractor _Subtract;
    Multiplier _Multiply;
    Divider _Divider;


};

#endif //THREADMANAGER_H
