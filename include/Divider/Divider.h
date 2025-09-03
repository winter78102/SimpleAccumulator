
#ifndef DIVIDER_H
#define DIVIDER_H

#include <Multiplier/Multiplier.h>
#include <cmath>

class Divider : public Multiplier {
public:
    Divider();

    std::vector<double> FixDataModel(const std::vector<double> &Storage);

private:

};

#endif //DIVIDER_H
