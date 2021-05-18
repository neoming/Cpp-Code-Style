#include <stdio.h>
#include <string.h>
class BigInt{
    char * digits;
    unsigned ndigits;
    unsigned size;
    BigInt(const BigInt& , const BigInt&);
    char fetch(int i)const;
public:
    BigInt(const char*);
    BigInt(unsigned = 0);
    BigInt(const BigInt&);
    BigInt& operator=(const BigInt&);
    BigInt& operator+=(const BigInt&);
    friend BigInt operator+(const BigInt&, const BigInt&);
    void print(FILE* = stdout) const;
    ~BigInt();
};

BigInt::~BigInt() {
    delete [] digits;
}

inline
char BigInt::fetch(int i) const {
    return i < ndigits ? digits[i] : 0;
}

inline
BigInt operator+(const BigInt& left, const BigInt& right){
    return BigInt(left,right);
}

BigInt& BigInt::operator+=(const BigInt &rhs) {
    unsigned max = 1 + (rhs.ndigits < ndigits
                            ? rhs.ndigits : ndigits);

    if (size < max){
        char *d = new char[size = max];
        for(int i = 0; i < ndigits; ++i)
            d[i] = digits[i];
        delete[]digits;
        digits = d;
    }
    while (ndigits<max)
        digits[ndigits++] = 0;
    for(int i = 0;i<ndigits;++i){
        digits[i] += rhs.fetch(i);
        if(digits[i] >= 10){
            digits[i] -= 10;
            digits[i+1] = 1;
        }
    }
    if(digits[ndigits-1] == 0)
        --ndigits;
    return *this;
}

void BigInt::print(FILE *f) const {
    for(int i = ndigits - 1; i>=0;i--){
        fprintf(f,"%c",digits[i]+'0');
    }
}

BigInt& BigInt::operator=(const BigInt &rhs) {
    if(this == &rhs)
        return *this;
    ndigits = rhs.ndigits;
    if( ndigits > size){
        delete [] digits;
        digits = new char[size=ndigits];
    }
    for(int i = 0;i< ndigits;++i){
        digits[i] = rhs.digits[i];
    }
    return *this;
}

BigInt::BigInt(const BigInt & left, const BigInt & right) {
    size = 1 + (left.ndigits > right.ndigits
                    ? left.ndigits : right.ndigits);
    digits = new char[size];
    ndigits = left.ndigits;
    for(int i = 0;i<ndigits;++i)
        digits[i] = left.digits[i];
    *this += right;
}

BigInt::BigInt(unsigned int n) {
    unsigned v = u;
    for(ndigits = 1;(v/=10)>0;++ndigits);
    digits = new char[size = ndigits];
    for(int i = 0;i<ndigits;++i){
        digits[i] = u%10;
        u /= 10;
    }
}

BigInt::BigInt(const BigInt& copyFrom){
    size = ndigits = copyFrom.ndigits;
    digits = new char[size];
    for(int i = 0;i<ndigits;++i)
        digits[i] = copyFrom.digits[i];
}

BigInt::BigInt(const char *s) {
    if(s[0] == '\0')
        s = "0";
    size = ndigits = strlen(s);
    digits = new char[size];
    for(int i = 0;i<ndigits;++i)
        digits[i] = s[ndigits-1-i]-'0';
}
