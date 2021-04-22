#include<stdio.h>

enum CARD { CDROM, TAPE, NETWORK };
enum MONITOR  { MONO, COLOR };

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

Component NetWork(600,"NetWork",45);

Component CDRom(1500,"CDRom",135);

Component Tape(1000,"Tape",45);

Component Color(1500,"Color");

Component Monochrome(500,"Mono");

class Computer{
    Component *card;
    Component *monitor;
public:
    Computer(CARD,MONITOR);
    ~Computer();
    int netPrice();
    void print();
};

int Computer::netPrice()
{
    return monitor->netPrice() + card->netPrice();
}

Computer::Computer(CARD card, MONITOR monitor)
{
    switch (card){
        case NETWORK:   this->card = &NetWork; break;
        case TAPE:      this->card = &Tape; break;
        case CDROM:     this->card = &CDRom; break;
    }
    switch (monitor){
        case MONO:      this->monitor = &Monochrome; break;
        case COLOR:     this->monitor = &Color; break;
    }
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
    Computer mn (NETWORK, MONO);
    Computer mc (CDROM, MONO);
    Computer mt (TAPE, MONO);
    Computer cn (NETWORK, COLOR);
    Computer cc (CDROM, COLOR);
    Computer ct (TAPE, COLOR);

    mn.print();
    mc.print();
    mt.print();
    cn.print();
    cc.print();
    ct.print();

    return 0;
}