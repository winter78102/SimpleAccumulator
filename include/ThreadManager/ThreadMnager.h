//
// Created by Bahar on 8/30/2025.
//

#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <iostream>
#include <Operator/Operator.h>
#include <Accumulator/Accumulator.h>
#include <memory>
#include <vector>
#include <functional>
#include <thread>
#include <future>


class ThreadManager {
public:
    int PossibleNumber();

    void SetThreadNumber();

    void SetInputSymbol(char Symbol);

    void FillThreads(const std::vector<int> &Storage);


private:

    int _ThreadNumber;
    std::vector<std::future<int>> _FutureOfTasks;
    std::vector<Operator> _TaskVector;
    char _InputSymbol;
    Accumulator _Accum;
    Subtractor _Subtract;
    Multiplier _Multiply;
    Divider _Divider;


};

#endif THREADMANAGER_H
