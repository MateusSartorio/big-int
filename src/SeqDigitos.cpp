#include "../h/SeqDigitos.h"

using namespace std;

SeqDigitos::SeqDigitos(BigInt& n) {
    dp = n.getDigitos();
    nd = n.getNdigitos();
}

unsigned SeqDigitos::operator++(int a) {
    if(nd == 0)
        return 0;

    nd--;
    return *dp++;
}

char* SeqDigitos::getDp() {
    return dp;
}

unsigned SeqDigitos::getNd() {
    return nd;
}

void SeqDigitos::print() {
    for(int i = nd - 1; i >= 0; i--)
        cout << (int) dp[i];
    cout << endl;
}