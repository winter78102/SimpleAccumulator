#include "Operator/Operator.h"

std::vector<double> &Operator::GetResult() {
    return _Result;
}

double Operator::GetLastElement() {
    int LastElementIndex = _Result.size() - 1;
    return _Result.at(LastElementIndex);
}

void Operator::DeleteObjectMemory() {
    _Result.clear();

}

