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


    std::vector<std::thread> ThreadVector;
    for (int i = 0; i < _ThreadNumber; i++) {
        ThreadVector.push_back(
                std::thread(&Operator::TaskDefinition, Channel, Storage, j,
                            i == _ThreadNumber - 1 ? j + ThreadSize + ModSize : j + ThreadSize, i));

        j += ThreadSize;
    }
    std::vector<double> TempResult;
    double Result;
    for (auto &t: ThreadVector) {
        t.join();
    }

    if (Channel == &_Subtract) {
        (&_Accum)->TaskDefinition(Channel->GetResult(), 0, Channel->GetResult().size(), 0);
        std::cout << ">>Result = " << (&_Accum)->GetLastElement() << std::endl;
        Channel->DeleteObjectMemory();
        (&_Accum)->DeleteObjectMemory();

    } else if (Channel == &_Divider) {
        (&_Multiply)->TaskDefinition(Channel->GetResult(), 0, Channel->GetResult().size(), 0);
        std::cout << ">>Result = " << (&_Multiply)->GetLastElement() << std::endl;
        Channel->DeleteObjectMemory();
        (&_Multiply)->DeleteObjectMemory();
    } else {
        Channel->TaskDefinition(Channel->GetResult(), 0, Channel->GetResult().size(), 0);
        std::cout << ">>Result = " << Channel->GetLastElement() << std::endl;
        Channel->DeleteObjectMemory();
    }
}

void ThreadManager::SetInputSymbol(char Symbol) {
    _InputSymbol = Symbol;
}


