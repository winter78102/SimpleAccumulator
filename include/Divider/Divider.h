
#ifndef DIVIDER_H
#define DIVIDER_H

#include <Operator/Operator.h>
#include <cmath>

class Divider : public Operator {
public:
    Divider();

    void TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex, int ThreadNumber) override;

private:

};

#endif //DIVIDER_H
