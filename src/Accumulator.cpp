#include <Accumulator/Accumulator.h>

double Accumulator::TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex) {
    if (Storage.empty()) { return -1; }
    double Result = 0;
    for (int i = StartIndex; i < EndIndex; i++) {
        Result += Storage[i];
    }
    return Result;
}

Accumulator::Accumulator() {
    _Symbol = '+';
}


