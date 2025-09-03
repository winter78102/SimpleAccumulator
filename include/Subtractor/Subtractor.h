

#ifndef SUBTRACTOR_H
#define SUBTRACTOR_H

#include <Accumulator/Accumulator.h>
#include <vector>

class Subtractor : public Accumulator {
public:
    Subtractor();

    std::vector<double> FixDataModel(const std::vector<double> &Storage);

};

#endif //SUBTRACTOR_H
