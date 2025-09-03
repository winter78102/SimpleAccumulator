

#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

#include <Operator/Operator.h>
#include <vector>

class Accumulator : public Operator {
public:
    Accumulator();

    Accumulator(const Accumulator &other) = default;

    void TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex, int ThreadNumber) override;

};

#endif //ACCUMULATOR_H
