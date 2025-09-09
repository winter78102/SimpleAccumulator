#include <ThreadManager/ThreadMnager.h>


int ThreadManager::PossibleNumber() {
    return std::thread::hardware_concurrency();
}


void ThreadManager::SetThreadNumber(int ThreadNumber) {
    _ThreadNumber = ThreadNumber;
}

void ThreadManager::FillThreads(const std::vector<double> &Storage, Operator &Channel) {
    int ThreadSize = Storage.size() / _ThreadNumber;
    int ModSize = Storage.size() - ThreadSize * _ThreadNumber;
    int j = 0;


    std::vector<std::thread> ThreadVector;
    for (int i = 0; i < _ThreadNumber; i++) {
        ThreadVector.push_back(
                std::thread(&Operator::TaskDefinition, &Channel, Storage, j,
                            i == _ThreadNumber - 1 ? j + ThreadSize + ModSize : j + ThreadSize, i));

        j += ThreadSize;
    }
    double Result;
    for (auto &t: ThreadVector) {
        t.join();
    }
    Result = Channel.LastResult(Channel.GetResult());
    std::cout << ">>Result = " << Result << std::endl;
    Channel.DeleteObjectMemory();
}


void ThreadManager::SetInputSymbol(char Symbol) {
    _InputSymbol = Symbol;
}


