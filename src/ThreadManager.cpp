#include <ThreadManager/ThreadMnager.h>


int ThreadManager::PossibleNumber() {
    return std::thread::hardware_concurrency();
}


void ThreadManager::SetThreadNumber() {
    int EnteredThreadNumber;
    while (1) {
        std::cout << ">>Enter the number of threads for calculation from 1 to " << PossibleNumber() << std::endl;
        std::cin >> EnteredThreadNumber;
        if (EnteredThreadNumber <= PossibleNumber()) {
            _ThreadNumber = EnteredThreadNumber;
            break;
        }
        std::cout << ">>Entered number is out of the range. \ntry again:\n ";
    }
}

void ThreadManager::FillThreads(const std::vector<int> &Storage) {
    int ThreadSize = Storage.size() / _ThreadNumber;
    int ModSize = Storage.size() - ThreadSize * _ThreadNumber;
    int j = 0;
    Operator *Channel = nullptr;

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

        _FutureOfTasks.push_back(std::async(std::launch::async, &Channel->TaskDefinition(), Storage, j,
                                            i == _ThreadNumber - 1 ? j + ThreadSize + ModSize : j + ThreadSize));
        j += ThreadSize;
    }

    int result = 0;

    for (auto &f: _FutureOfTasks) {
        result += f.get();   // waits if not finished yet
    }
    std::cout << ">>Sum = " << result << std::endl;
}

void ThreadManager::SetInputSymbol(char Symbol) {
    _InputSymbol = Symbol;
}


