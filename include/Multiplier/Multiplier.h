
#ifndef MULTIPLIER_H
#define MULTIPLIER_H

#include <Operator/Operator.h>

class Multiplier : public Operator {
public:
    Multiplier();

    double TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex) override;

private:

};

#endif //MULTIPLIER_H
