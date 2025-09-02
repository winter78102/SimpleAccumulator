#include <Multiplier/Multiplier.h>

int Multiplier::TaskDefinition(const std::vector<int> &Storage, int StartIndex, int EndIndex) {
    if (Storage.empty()) { return -1; }
    int Result = Storage[StartIndex];
    for (int i = StartIndex + 1; i < EndIndex; i++) {
        Result *= Storage[i];
    }
    return Result;
}

Multiplier::Multiplier() {
    _Symbol = '*';
}
