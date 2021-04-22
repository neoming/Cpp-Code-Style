#include <iostream>
using namespace std;
class ChemicalElement{
    private:
        unsigned atomicNumber;
        float atomicWeight;
        float pricePerOunce;
    public:
        ChemicalElement(unsigned an, float aw, float p)
        {
            atomicNumber = an;
            atomicWeight = aw;
            pricePerOunce = p;
        };
        unsigned getAtomicNumber(){return atomicNumber;}
        float getAtomicWeight(){return atomicWeight;}
        float getPricePerOunce(){return pricePerOunce;}
        void output()
        {
            cout<< "The atomic weight: " << atomicWeight << endl;
            cout<< "The atomic Number: " << atomicNumber << endl;
            cout<< "Price per ounce: " << pricePerOunce << endl;
        }
};

class Pb : public ChemicalElement{
    public:
        Pb(unsigned an = 82, float aw = 207.2, float p = 0.01) : ChemicalElement(an, aw, p){}
};

class Au : public ChemicalElement{
    public:
        Au(unsigned an = 79, float aw = 196.9665, float p = 450.75) : ChemicalElement(an, aw, p){}
};

int main(){
    Pb myLead;
    Au myGod;
    myGod.output();
}