

#ifndef SUBTRACTOR_H
#define SUBTRACTOR_H

#include <Accumulator/Accumulator.h>
#include <vector>

class Subtractor : public Accumulator {
public:
    Subtractor();

    void TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex, int ThreadNumber) override;

};

#endif //SUBTRACTOR_H
