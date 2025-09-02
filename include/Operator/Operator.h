
#ifndef OPERATOR_H
#define OPERATOR_H

#include <Accumulator/Accumulator.h>
#include <Subtractor/Subtractor.h>
#include <Multiplier/Multiplier.h>
#include <Divider/Divider.h>
#include <vector>
#include <memory>
#include <functional>

class Operator {
public:

    Operator() = default;

    Operator(const Operator &other) = default;

    ~Operator() = default;

    virtual int TaskDefinition(const std::vector<int> &Storage, int StartIndex, int EndIndex);


protected:
    char _Symbol;


};


#endif //OPERATOR_H
