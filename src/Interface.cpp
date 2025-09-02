#include <Interface/Interface.h>
#include <Operator/Operator.h>

void Interface::SelectStage() {
    while (1) {
        std::cout << ">>how do you want to enter input type the number\n";
        std::cout << "1 . by files\n2 . by consol\n>>";
        int Input;
        std::cin >> Input;
        if (Input == 1 || Input == 2) {
            _SelectButton = Input;
            break;
        }
        std::cerr << "wrong input try again\n";
    }
}


void Interface::Calculate() {
    std::vector<double> Storage;
    Reader *InputChannel;
    switch (_SelectButton) {
        case 1:
            InputChannel = &_File;
            break;

        case 2:
            InputChannel = &_Consol;
            break;
    }

    InputChannel->GetString();
    InputChannel->Read();
    Storage = InputChannel->GetStorage();
    _ThreadManager.SetThreadNumber(Storage);
    SetOperatorSymbol();
    _ThreadManager.FillThreads(Storage);
}

void Interface::SetOperatorSymbol() {
    char Symbol;
    std::cout << ">>Enter your desired operation symbol from + / * -" << std::endl;
    std::cin >> Symbol;
    _ThreadManager.SetInputSymbol(Symbol);
}







