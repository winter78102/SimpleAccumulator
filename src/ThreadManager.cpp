#include <ThreadManager/ThreadMnager.h>


int ThreadManager::PossibleNumber() {
    return std::thread::hardware_concurrency();
}


void ThreadManager::SetThreadNumber(const std::vector<double> &Storage) {
    int EnteredThreadNumber;
    while (1) {
        std::cout << ">>Enter the number of threads for calculation from 1 to "
                  << std::min<int>(PossibleNumber(), Storage.size()) << std::endl;
        std::cin >> EnteredThreadNumber;
        if (EnteredThreadNumber <= PossibleNumber()) {
            _ThreadNumber = EnteredThreadNumber;
            break;
        }
        std::cout << ">>Entered number is out of the range. \ntry again:\n ";
    }
}

void ThreadManager::FillThreads(const std::vector<double> &Storage) {
    int ThreadSize = Storage.size() / _ThreadNumber;
    int ModSize = Storage.size() - ThreadSize * _ThreadNumber;
    int j = 0;
    Operator *Channel;
    switch (_InputSymbol) {
        case '+':
            Channel = &_Accum;
            break;
        case '-':
            Channel = &_Subtract;
            break;
        case '*':
            Channel = &_Multiply;
            break;
        case '/':
            Channel = &_Divider;
            break;
    }
    for (int i = 0; i < _ThreadNumber; i++) {
        _FutureOfTasks.push_back(std::async(std::launch::async,
                                            &Operator::TaskDefinition, Channel, Storage, j,
                                            (i == _ThreadNumber - 1 ? j + ThreadSize + ModSize : j + ThreadSize)));
        j += ThreadSize;
    }
    std::vector<double> TempResult;
    double Result;
    for (auto &f: _FutureOfTasks) {
        TempResult.push_back(f.get());
    }

    if (TempResult.size() > 1) {
        Result = Channel->TaskDefinition(TempResult, 0, TempResult.size());
    } else {
        Result = TempResult.at(0);
    }
    std::cout << ">>Result = " << Result << std::endl;
}

void ThreadManager::SetInputSymbol(char Symbol) {
    _InputSymbol = Symbol;
}


