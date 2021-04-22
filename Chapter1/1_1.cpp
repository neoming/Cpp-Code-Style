#include<stdio.h>

enum CARD { CDROM, TAPE, NETWORK };
enum MONITOR  { MONO, COLOR };

class Card{
public:
virtual int price() = 0;
virtual char *name() = 0;
virtual int rebate();
};

class NetWork : public Card{
public:
    int price();
    char *name();
};

class CDRom : public Card{
public:
    int price();
    char *name();
    int rebate();
};

class Tape : public Card{
public:
    int price();
    char *name();
};

class Monitor{
public:
virtual int price()=0;
virtual char *name()=0;
};

class Color : public Monitor{
public:
    int price();
    char *name();
};

class Monochrome : public Monitor {
public:
    int price();
    char *name();
};

int Card::rebate() {return 45;}

int NetWork::price() {return 600;}
char *NetWork::name() {return "Network";}

int CDRom::price() {return 1500;}
char *CDRom::name() {return "CDRom";}
int CDRom::rebate() {return 135;}

int Tape::price() {return 1000;}
char *Tape::name() {return "Tape";}

int Color::price() {return 1500;}
char *Color::name() {return "Color";}

int Monochrome::price() {return 500;}
char *Monochrome::name(){return "Mono";}

class Computer{
    Card *card;
    Monitor *monitor;
public:
    Computer(CARD,MONITOR);
    ~Computer();
    int netPrice();
    void print();
};

int Computer::netPrice()
{
    return monitor->price() + card->price() - card->rebate();
}

Computer::Computer(CARD card, MONITOR monitor)
{
    switch (card){
        case NETWORK:   this->card = new NetWork; break;
        case TAPE:      this->card = new Tape; break;
        case CDROM:     this->card = new CDRom; break;
    }
    switch (monitor){
        case MONO:      this->monitor = new Monochrome; break;
        case COLOR:     this->monitor = new Color; break;
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