
#ifndef CONSOL_H
#define CONSOL_H

#include "iostream"
#include "Parser/Parser.h"

class Consol : public Parser {
public:
    void GetString() override;

};

#endif //CONSOL_H
