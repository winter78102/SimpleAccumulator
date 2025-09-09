#include <Operator/Divider/Divider.h>

void Divider::TaskDefinition(const std::vector<double> &Storage, int StartIndex, int EndIndex, int ThreadNumber) {
    if (Storage.empty()) { return; }
    double Result = 1;
    if (ThreadNumber != 0) {
        for (int i = StartIndex; i < EndIndex; i++) {
            Result *= Storage[i];

        }
        Result = 1 / Result;
    } else {
        double FirstNumber = Storage[0];
        for (int i = StartIndex + 1; i < EndIndex; i++) {
            Result *= Storage[i];
        }
        Result = 1 / Result;
        Result = Result * FirstNumber;
    }


    _Mutex.lock();
    _Result.push_back(Result);
    _Mutex.unlock();
}

Divider::Divider() {
    _Symbol = '/';
}

double Divider::LastResult(const std::vector<double> &Storage) {
    return _MultiplyObj.LastResult(Storage);
}

