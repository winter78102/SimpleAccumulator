#include <Multiplier/Multiplier.h>

void Multiplier::TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex, int ThreadNumber) {
//    if (Storage.empty()) { return -1; }
    double Result = 1;
    for (int i = StartIndex; i < EndIndex; i++) {
        Result *= Storage[i];
    }

    _Mutex.lock();
    _Result.push_back(Result);
    _Mutex.unlock();
}

Multiplier::Multiplier() {
    _Symbol = '*';
}
