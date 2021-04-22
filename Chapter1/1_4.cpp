#include<stdio.h>

class Component{
    private:
        int price_;
        char* name_;
        int rebate_;
    public:
        Component(int p, char* n, int r = 0);
        int price();
        char* name();
        int rebate();
        int netPrice();
};

Component::Component(int p, char* n, int r){
    price_ = p;
    name_ = n;
    rebate_ = r;
}

int Component::rebate() {
    return rebate_;
}

int Component::price(){
    return price_;
}

int Component::netPrice() {
    return price_-rebate_;
}

char* Component::name() {
    return name_;
}

class Card : public Component{
    public:
        Card(int p, char* n, int r = 45) : Component(p,n,r){}
};

class Monitor : public Component{
    public:
        Monitor(int p, char* n, int r = 0) : Component(p,n,r){}
};

Card NetWork(600,"NetWork");

Card CDRom(1500,"CDRom",135);

Card Tape(1000,"Tape");

Monitor Color(1500,"Color");

Monitor Monochrome(500,"Mono");

class Computer{
    Card *card;
    Monitor *monitor;
public:
    Computer(Card*,Monitor*);
    ~Computer();
    int netPrice();
    void print();
};

int Computer::netPrice()
{
    return monitor->netPrice() + card->netPrice();
}

Computer::Computer(Card* c, Monitor* m)
{
    card = c;
    monitor = m;
}

Computer::~Computer()
{
    delete card;
    delete monitor;
}

void Computer::print()
{
    printf("%s %s, net price = %d\n",
            card->name(),monitor->name(),netPrice());
}

int main()
{
    Computer mn (&NetWork, &Monochrome);
    Computer mc (&CDRom, &Monochrome);
    Computer mt (&Tape, &Monochrome);
    Computer cn (&NetWork, &Color);
    Computer cc (&CDRom, &Color);
    Computer ct (&Tape, &Color);

    mn.print();
    mc.print();
    mt.print();
    cn.print();
    cc.print();
    ct.print();

    return 0;
}