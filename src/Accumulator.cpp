#include <Accumulator/Accumulator.h>

int Accumulator::TaskDefinition(const std::vector<int> &Storage, int StartIndex, int EndIndex) {
    if (Storage.empty()) { return -1; }
    int Result = 0;
    for (int i = StartIndex; i < EndIndex; i++) {
        Result += Storage[i];
    }
    return Result;
}

Accumulator::Accumulator() {
    _Symbol = '+';
}


