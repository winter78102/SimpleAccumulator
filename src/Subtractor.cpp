#include <Subtractor/Subtractor.h>

double Subtractor::TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex) {
    if (Storage.empty()) { return -1; }
    double Result = Storage[0];
    for (int i = StartIndex; i < EndIndex - 1; i++) {
        Result = Result - Storage[i + 1];
    }
    return Result;
}

Subtractor::Subtractor() {
    _Symbol = '-';
}
