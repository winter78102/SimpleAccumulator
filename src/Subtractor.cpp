#include <Subtractor/Subtractor.h>

int Subtractor::TaskDefinition(const std::vector<int> &Storage, int StartIndex, int EndIndex) {
    if (Storage.empty()) { return -1; }
    int Result = Storage[StartIndex];
    for (int i = StartIndex + 1; i < EndIndex; i++) {
        Result -= Storage[i];
    }
    return Result;
}

Subtractor::Subtractor() {
    _Symbol = '-';
}
