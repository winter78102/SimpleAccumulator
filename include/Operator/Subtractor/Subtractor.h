

#ifndef SUBTRACTOR_H
#define SUBTRACTOR_H

#include <Operator/Operator.h>
#include <Operator/Accumulator/Accumulator.h>
#include <vector>

class Subtractor : public Operator {
public:
    Subtractor();

    void TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex, int ThreadNumber) override;

    double LastResult(const std::vector<double> &Storage) override;

private:
    Accumulator _AccumObj;
};

#endif //SUBTRACTOR_H
