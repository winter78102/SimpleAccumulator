
#ifndef OPERATOR_H
#define OPERATOR_H

#include <vector>
#include <memory>
#include <functional>

class Operator {
public:

    Operator() = default;

    Operator(const Operator &other) = default;

    ~Operator() = default;

    virtual double TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex) = 0;


protected:
    char _Symbol;


};


#endif //OPERATOR_H
