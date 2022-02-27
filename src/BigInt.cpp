#include <string.h>
#include "../h/BigInt.h"

using namespace std;

BigInt::BigInt(const char* digitString) {
    unsigned n = strlen(digitString);

    if(n != 0) {
        digitos = new char[ndigitos = n];
        char* p = digitos;
        const char* q = &digitString[n];

        while(n--)
            *p++ = *--q - '0';
    }
    else {
        //string vazia
        digitos = new char[ndigitos = 1];
        digitos[0] = 0;
    }
}

BigInt::BigInt(unsigned n) {
    char d[3*sizeof(unsigned) + 1];
    char* dp = d;
    ndigitos = 0;

    do {
        *dp++ = n%10;
        n /= 10;
        ndigitos++;
    } while(n > 0);

    digitos = new char[ndigitos];
    for(int i = 0; i < ndigitos; i++)
        digitos[i] = d[i];
}

BigInt::BigInt(const BigInt& n) {
    unsigned i = n.ndigitos;
    digitos = new char[ndigitos = i];
    char* p = digitos;
    char* q = n.digitos;

    while(i--)
        *p++ = *q++;
}

BigInt::BigInt(char* d, unsigned n) {
    digitos = d;
    ndigitos = n;
}

void BigInt::operator=(const BigInt& n) {
    if(this == &n)
        return;
    
    delete digitos;

    unsigned i = n.ndigitos;
    digitos = new char[ndigitos = i];

    char* p = digitos;
    char* q = n.digitos;

    while(i--)
        *p++ = *q++;
}

BigInt BigInt::operator+(const BigInt& n) const {
    unsigned maxDigitos = (ndigitos > n.ndigitos ? ndigitos : n.ndigitos) + 1;

    char* sumPtr = new char[maxDigitos];

    BigInt sum(sumPtr, maxDigitos);

    SeqDigitos a((BigInt&) *this);
    SeqDigitos b((BigInt&) n);

    unsigned i = maxDigitos - 1;
    unsigned carry = 0;

    while(i--) {

        *sumPtr = (a++) + (b++) + carry;

        if(*sumPtr >= 10) {
            carry = 1;
            *sumPtr -= 10;
        }
        else
            carry = 0;
        
        sumPtr++;
    }
    
    if(carry) {
        *sumPtr = 1;
        return sum;
    }
    
    else {
        char* p = new char[maxDigitos - 1];
        char* q = sum.digitos;

        for(int i = 0; i < maxDigitos - 1; i++)
            p[i] = q[i];

        BigInt s(p, maxDigitos - 1);

        return s;
    }    
}

char* BigInt::getDigitos() {
    return digitos;
}

unsigned BigInt::getNdigitos() {
    return ndigitos;
}

void BigInt::setDigitos(char* d) {
    digitos = d;
}

void BigInt::setNdigitos(unsigned n) {
    ndigitos = n;
}

void BigInt::print(FILE* f) const {
    for(int i = ndigitos - 1; i >= 0; i--)
        fprintf(f, "%d", digitos[i]);
    fprintf(f, "\n");
}