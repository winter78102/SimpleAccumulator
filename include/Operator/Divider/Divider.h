
#ifndef DIVIDER_H
#define DIVIDER_H


#include <Operator/Operator.h>
#include <Operator/Multiplier/Multiplier.h>
#include <cmath>

class Divider : public Operator {
public:
    Divider();

    void TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex, int ThreadNumber) override;

    double LastResult(const std::vector<double> &Storage) override;

private:
    Multiplier _MultiplyObj;

};

#endif //DIVIDER_H
