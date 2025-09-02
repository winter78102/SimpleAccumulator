
#ifndef DIVIDER_H
#define DIVIDER_H

#include <Operator/Operator.h>

class Divider : public Operator {
public:
    Divider() = default;

    int TaskDefinition(const std::vector<int> &Storage, int StartIndex, int EndIndex) override;

private:

};

#endif //DIVIDER_H
