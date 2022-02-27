#ifndef SEQDIGITOS_H
#define SEQDIGITOS_H

#include <iostream>
#include "./BigInt.h"

class SeqDigitos {

    private:
        char* dp;
        unsigned nd;

    public:
        SeqDigitos(BigInt&);
        unsigned operator++(int);

        char* getDp();
        unsigned getNd();

        void print();

};

#endif