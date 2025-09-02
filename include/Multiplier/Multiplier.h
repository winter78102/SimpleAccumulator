
#ifndef MULTIPLIER_H
#define MULTIPLIER_H

#include <Operator/Operator.h>

class Multiplier : public Operator {
public:
    Multiplier();

    int TaskDefinition(const std::vector<int> &Storage, int StartIndex, int EndIndex) override;

private:

};

#endif //MULTIPLIER_H
