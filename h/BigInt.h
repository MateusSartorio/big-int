#ifndef BIGINT_H
#define BIGINT_H

#include <stdio.h>
#include <iostream>

class BigInt {

    private:
        char* digitos;
        unsigned ndigitos;

        BigInt(char*, unsigned);

    public:
        BigInt(const char*);
        BigInt(unsigned n = 0);
        BigInt(const BigInt&);

        void operator=(const BigInt&);
        BigInt operator+(const BigInt&) const;

        char* getDigitos();
        unsigned getNdigitos();

        void setDigitos(char* d);
        void setNdigitos(unsigned n);

        void print(FILE* f = stdout) const;

        ~BigInt() {delete digitos;}
};

#include "./SeqDigitos.h"

#endif