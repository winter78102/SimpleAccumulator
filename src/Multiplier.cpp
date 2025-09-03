#include <Multiplier/Multiplier.h>

double Multiplier::TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex) {
    if (Storage.empty()) { return -1; }
    double Result = 1;
    for (int i = StartIndex; i < EndIndex; i++) {
        Result *= Storage[i];
    }
    return Result;
}

Multiplier::Multiplier() {
    _Symbol = '*';
}
