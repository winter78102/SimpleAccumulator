

#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

#include <Operator/Operator.h>
#include <vector>

class Accumulator : public Operator {
public:
    Accumulator();

    Accumulator(const Accumulator &other) = default;

    int TaskDefinition(const std::vector<int> &Storage, int StartIndex, int EndIndex) override;

};

#endif //ACCUMULATOR_H
