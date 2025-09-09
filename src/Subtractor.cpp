#include <Operator/Subtractor/Subtractor.h>


void Subtractor::TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex, int ThreadNumber) {
//    if (Storage.empty()) { return -1; }
    double Result = 0;
    if (ThreadNumber != 0) {
        for (int i = StartIndex; i < EndIndex; i++) {
            Result += Storage[i];

        }
        Result = -1 * Result;
    } else {
        double FirstNumber = Storage[0];
        for (int i = StartIndex + 1; i < EndIndex; i++) {
            Result += Storage[i];
        }
        Result = -1 * Result;
        Result = Result + FirstNumber;
    }


    _Mutex.lock();
    _Result.push_back(Result);
    _Mutex.unlock();
}


Subtractor::Subtractor() {
    _Symbol = '-';
}

double Subtractor::LastResult(const std::vector<double> &Storage) {
    return _AccumObj.LastResult(Storage);
}
