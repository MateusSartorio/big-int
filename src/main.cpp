#include <iostream>
#include <stdio.h>
#include "../h/BigInt.h"

using namespace std;

void inc(int& x) {
    x++;
}

int main(int argn, char* argv[]) {
    const BigInt a = "123";
    const BigInt b("2456");
    BigInt c;

    c = a + b + 47;

    a.print();
    b.print();
    c.print();

    return 0;
}