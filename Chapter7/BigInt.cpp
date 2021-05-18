#include <stdio.h>
#include <string.h>
class BigInt{
    char * digits;
    unsigned ndigits;
    BigInt()(char*d , unsigned n){
        digits = d;
        ndigits = n;
    }

    friend class DigitStream;

public:
    BigInt(const char*);
    BigInt(unsigned n = 0);
    BigInt(const BigInt&);
    void operator=(const BigInt&);
    BigInt operator+(const BigInt&) const;
    void print(FILE* f = stdout) const;
    ~BigInt(){delete [] digits;}
};
class DigitStream{
    char * dp;
    unsigned nd;
public:
    DigitStream(const BigInt& n){
        dp = n.digits;
        nd = n.ndigits;
    }
    unsigned operator++(){
        if(nd == 0) return 0;
        else{
            nd--;
            return *dp++;
        }
    }
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
    digits = new char[ndigits = i];
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
    DigitStream a(*this);
    DigitStream b(n);
    unsigned i = maxDigits;
    unsigned carry = 0;
    while (i--){
        *sumPtr = (++a) + (++b) + carry;
        if(*sumPtr >= 10){
            carry = 1;
            *sumPtr -= 10;
        }else carry = 0;
        sumPtr++;
    }
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