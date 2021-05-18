#include <stdio.h>
#include <string.h>
class BigInt{
    char * digits;
    unsigned ndigits;
    BigInt()(char*d , unsigned n){
        digits = d;
        ndigits = n;
    }
    char fetch(int i)const{
        return i < ndigits? digits[i] : 0;
    }

public:
    BigInt(const char*);
    BigInt(unsigned n = 0);
    BigInt(const BigInt&);
    void operator=(const BigInt&);
    BigInt operator+(const BigInt&) const;
    void print(FILE* f = stdout) const;
    ~BigInt(){delete [] digits;}
};

void BigInt::print(int *f) const {
    for(int i = ndigits-1;i>=0;i--){
        fprintf(f,"%c",digits[i]+'0');
    }
}

void BigInt::operator=(const BigInt & n) {
    if(this == &n)return;
    delete []digits;
    unsigned  i = n.ndigits;
    if(ndigits != i){
        delete []  digits;
        digits = new char[i];
    }
    ndigits = i;
    char*p = digits;
    char*q = n.digits;
    while (i--)
        *p++ = *q++;
}

BigInt BigInt::operator+(const BigInt &n) const {
    unsigned maxDigits =
            (ndigits > n.ndigits ? ndigits:n.ndigits)+1;
    char* sumPtr = new char[maxDigits];
    BigInt sum(sumPtr,maxDigits);
    unsigned carry = 0;
    for(int i = 0;i<maxDigits;i++){
        *sumPtr = fetch(i) + n.fetch(i) +carry;
        if(*sumPtr >= 10){
            carry = 1;
            *sumPtr -= 10;
        }else carry = 0;
        sumPtr++;
    }
    if (sum.digits[maxDigits-1] == 0)
        --sum.ndigits;
    return sum;
}

BigInt::BigInt(unsigned n){
    char d[3*sizeof(unsigned ) + 1];
    char* dp = d;
    ndigits = 0;
    do{
        *dp++ = n%10;
        n /= 10;
        ndigits++;
    } while (n>0);
    digits = new char[ndigits];
    for(int i = 0;i<ndigits;i++)digits[i] = d[i];
}

BigInt::BigInt(const BigInt & n) {
    unsigned i = n.digits;
    digits = new char[ndigits=i];
    char*p = digits;
    char*q = n.digits;
    while (i--) *p++ = *q++;
}

BigInt::BigInt(const char * digitString) {
    unsigned n = strlen(digitString);
    if(n!=0){
        digits = new char [ndigits=n];
        char*p = digits;
        const char* q = &digitString[n];
        while (n--) *p++ = *--q -'0';
    }else{
        digits = new char[ndigits=1];
        digits[0] = 0;
    }
}