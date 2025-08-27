#include <iostream>
#include <Interface/Interface.h>

int main() {
    Interface InterfaceObj;
    while (1) {
        InterfaceObj.SelectStage();
        InterfaceObj.Calculate();
    }
    return 0;
}
