#include <Client/Client.h>


void Client::SelectReader(int Selector) {
    Parser *InputChannel;
    switch (Selector) {
        case 1:
            InputChannel = &_File;
            break;

        case 2:
            InputChannel = &_Consol;
            break;
    }
    InputChannel->GetString();
    InputChannel->Parse();
    _Storage = InputChannel->GetStorage();
}

void Client::SelectOperator(char Sign) {
    Operator *OperatorObj;
    switch (Sign) {
        case '+':
            OperatorObj = &_Accum;
            break;
        case '-':
            OperatorObj = &_Subtract;
            break;
        case '*':
            OperatorObj = &_Multiply;
            break;
        case '/':
            OperatorObj = &_Divider;
            break;
    }
    _ThreadManage.FillThreads(_Storage, *OperatorObj);

}

void Client::SelectThreadNumber() {
    while (1) {

        std::cout << ">>Enter the number of threads for calculation from 1 to "
                  << std::min<int>(_ThreadManage.PossibleNumber(), _Storage.size()) << std::endl;
        int EnteredThreadNumber;
        std::cin >> EnteredThreadNumber;
        if (EnteredThreadNumber <= _ThreadManage.PossibleNumber()) {
            _ThreadManage.SetThreadNumber(EnteredThreadNumber);
            break;
        }
        std::cout << ">>Entered number is out of the range. \ntry again:\n ";
    }
}


