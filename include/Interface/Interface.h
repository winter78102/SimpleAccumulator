

#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>
#include <Client/Client.h>
#include <numeric>
#include <Operator/Operator.h>


class Interface {
public:

    void SelectStage();

    void ThreadNumber();

    void SetOperatorSymbol();


private:

    Client _Client;


};

#endif //INTERFACE_H
