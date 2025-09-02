

#ifndef SUBTRACTOR_H
#define SUBTRACTOR_H

#include <Operator/Operator.h>
#include <vector>

class Subtractor : public Operator {
public:
    Subtractor();

    double TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex) override;
};

#endif //SUBTRACTOR_H
