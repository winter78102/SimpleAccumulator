

#ifndef SUBTRACTOR_H
#define SUBTRACTOR_H

#include <Operator/Operator.h>
#include <vector>

class Subtractor : public Operator {
public:
    Subtractor();

    int TaskDefinition(const std::vector<int> &Storage, int StartIndex, int EndIndex) override;
};

#endif //SUBTRACTOR_H
