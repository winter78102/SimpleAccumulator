#include <Divider/Divider.h>

double Divider::TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex) {
    if (Storage.empty()) { return -1; }
    double Result = 0;
    for (int i = StartIndex; i < EndIndex - 1; i++) {
        Result = Storage[i] / Storage[i + 1];
    }
    return Result;
}

Divider::Divider() {
    _Symbol = '/';
}

