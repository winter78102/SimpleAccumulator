
#ifndef CONSOL_H
#define CONSOL_H

#include "iostream"
#include "Reader/Reader.h"

class Consol : public Reader {
public:
    void GetString() override;

};

#endif //CONSOL_H
