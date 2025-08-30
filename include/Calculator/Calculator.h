//
// Created by Bahar on 8/30/2025.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <thread>
#include <future>
#include <chrono>

class Calculator {
public:
    int PossibleNumber();

    static int AccumTask(const std::vector<int> &Storage, int StartIndex, int EndIndex);

    void FillTaskQueue();

    void SetThreadNumber();

    void FillThreadsQueue(const std::vector<int> &Storage);


private:
    std::vector<std::shared_ptr<std::function<int(const std::vector<int> &, int, int)>>> _TaskQueue;
    int _ThreadNumber;
    std::vector<std::future<int>> _FutureOfTasks;

};

#endif CALCULATOR_H
