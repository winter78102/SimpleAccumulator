#include <iostream>
#include <Interface/Interface.h>

int main() {
    Interface InterfaceObj;
    while (1) {
        InterfaceObj.SelectStage();
        InterfaceObj.ThreadNumber();
        InterfaceObj.SetOperatorSymbol();
    }
    return 0;
}
