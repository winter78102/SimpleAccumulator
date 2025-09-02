
#ifndef DIVIDER_H
#define DIVIDER_H

#include <Operator/Operator.h>

class Divider : public Operator {
public:
    Divider();

    double TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex) override;

private:

};

#endif //DIVIDER_H
