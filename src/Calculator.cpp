#include <Calculator/Calculator.h>

int Calculator::PossibleNumber() {
    return std::thread::hardware_concurrency();
}

int Calculator::AccumTask(const std::vector<int> &Storage, int StartIndex, int EndIndex) {
    if (Storage.empty()) { return -1; }
    int Sum = 0;
    for (int i = StartIndex; i < EndIndex; i++) {
        Sum += Storage[i];
    }
    return Sum;
}

void Calculator::FillTaskQueue() {
    _TaskQueue.push_back(std::make_shared<std::function<int(const std::vector<int> &, int, int)>>(AccumTask));
}


void Calculator::SetThreadNumber() {
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

void Calculator::FillThreadsQueue(const std::vector<int> &Storage) {
    int ThreadSize = Storage.size() / _ThreadNumber;
    int ModSize = Storage.size() - ThreadSize * _ThreadNumber;
    int j = 0;
    for (int i = 0; i < _ThreadNumber; i++) {

        _FutureOfTasks.push_back(std::async(std::launch::async, *_TaskQueue[0], Storage, j,
                                            i == _ThreadNumber - 1 ? j + ThreadSize + ModSize : j + ThreadSize));
        j += ThreadSize;
    }

    int result = 0;

    for (auto &f: _FutureOfTasks) {
        result += f.get();   // waits if not finished yet
    }
    std::cout << ">>Sum = " << result << std::endl;
}
