#include <Interface/Interface.h>

void Interface::SelectStage() {
    while (1) {
        std::cout << ">>how do you want to enter input type the number\n";
        std::cout << "1 . by files\n2 . by consol\n>>";
        int Input;
        std::cin >> Input;
        if (Input == 1 || Input == 2) {
            _Client.SelectReader(Input);
            break;
        }
        std::cerr << "wrong input try again\n";
    }
}

void Interface::SetOperatorSymbol() {
    char Symbol;
    std::cout << ">>Enter your desired operation symbol from + / * -" << std::endl;
    std::cin >> Symbol;
    _Client.SelectOperator(Symbol);
}

void Interface::ThreadNumber() {
    _Client.SelectThreadNumber();
}







