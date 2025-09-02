

#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

#include <Operator/Operator.h>
#include <vector>

class Accumulator : public Operator {
public:
    Accumulator();

    Accumulator(const Accumulator &other) = default;

    double TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex) override;

};

#endif //ACCUMULATOR_H
