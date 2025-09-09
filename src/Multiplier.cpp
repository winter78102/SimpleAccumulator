#include <Operator/Multiplier/Multiplier.h>

void Multiplier::TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex, int ThreadNumber) {
//    if (Storage.empty()) { return -1; }
    double Result = 1;
    for (int i = StartIndex; i < EndIndex; i++) {
        Result *= Storage[i];
    }
    std::lock_guard<std::mutex> guard(_Mutex);
    _Result.push_back(Result);
}

Multiplier::Multiplier() {
    _Symbol = '*';
}

double Multiplier::LastResult(const std::vector<double> &Storage) {
    double Result = 1;
    for (double i: Storage) {
        Result *= i;
    }
    return Result;
}
