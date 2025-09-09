
#ifndef OPERATOR_H
#define OPERATOR_H

#include <vector>
#include <memory>
#include <functional>
#include <mutex>

class Operator {
public:

    Operator() = default;

    Operator(const Operator &other) = default;

    ~Operator() = default;

    virtual void TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex, int ThreadNumber) = 0;

    virtual double LastResult(const std::vector<double> &Storage) = 0;

    std::vector<double> &GetResult();

    void DeleteObjectMemory();

    double GetLastElement();

protected:
    char _Symbol;
    std::vector<double> _Result;
    std::mutex _Mutex;


};


#endif //OPERATOR_H
