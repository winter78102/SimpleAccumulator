
#ifndef MULTIPLIER_H
#define MULTIPLIER_H

#include <Operator/Operator.h>

class Multiplier : public Operator {
public:
    Multiplier();

    void TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex, int ThreadNumber) override;

private:

};

#endif //MULTIPLIER_H
