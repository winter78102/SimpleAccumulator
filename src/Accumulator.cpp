#include <Accumulator/Accumulator.h>

void Accumulator::TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex, int ThreadNumber) {
//    if (Storage.empty()) { return -1; }
    double Result = 0;
    for (int i = StartIndex; i < EndIndex; i++) {
        Result += Storage[i];
    }
    _Mutex.lock();
    _Result.push_back(Result);
    _Mutex.unlock();
}

Accumulator::Accumulator() {
    _Symbol = '+';
}


