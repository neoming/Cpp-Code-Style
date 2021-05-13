#include <stdio.h>
#include <string.h>

class Vehicle
{
protected:
    char *plate;

public:
    Vehicle() { plate = NULL; }
    Vehicle(char *p)
    {
        plate = new char[strlen(p) + 1];
        strcpy(plate, p);
    }
    ~Vehicle() { delete[] plate; }

    virtual void identify()
    {
        printf("generic vehicle\n");
    }
};

class Car : public Vehicle
{
public:
    Car() : Vehicle() {}
    Car(char *p) : Vehicle(p) {}
    void identify()
    {
        if (plate)
        {
            printf("car with plate %s\n", plate);
        }
        else
        {
            printf("car with plate <none>\n");
        }
    }
};

class Truck : public Vehicle
{
public:
    Truck() : Vehicle() {}
    Truck(char *p) : Vehicle(p) {}

    void identify()
    {
        if(plate)
        {
            printf("truck with plate %s\n", plate);
        }
        else
        {
            printf("truck with plate <none>\n");
        }
    }
};

class Garage
{
    int maxVehicles;
    Vehicle **parked;

public:
    Garage(int max)
    {
        maxVehicles = max;
        parked = new Vehicle *[maxVehicles];
        for (int bay = 0; bay < maxVehicles; ++bay)
        {
            parked[bay] = NULL;
        }
    }

    ~Garage()
    {
        delete[] parked;
    }

    int accept(Vehicle *vec)
    {
        for (int bay = 0; bay < maxVehicles; ++bay)
        {
            if (parked[bay] == NULL)
            {
                parked[bay] = vec;
                return bay;
            }
        }
        return -1;
    }

    Vehicle *release(int bay)
    {
        if (bay < 0 || bay >= maxVehicles)
            return NULL;
        Vehicle *vec = parked[bay];
        parked[bay] = NULL;
        return vec;
    }

    void listVehicles()
    {
        for (int bay = 0; bay < maxVehicles; ++bay)
        {
            if (parked[bay] != NULL)
            {
                printf("Vehicle in bay %d is: ", bay);
                parked[bay]->identify();
            }
        }
    }
};

Car c1("RVR 101");
Car c2("SPT 202");
Car c3("CHP 303");
Car c4("BDY 404");
Car c5("BCH 505");

Truck t1("TBL 606");
Truck t2("IFY 707");
Truck t3("FFY 808");
Truck t4("PCS 909");
Truck t5("SLY 000");

int main()
{
    Garage Park(15);
    Park.accept(&c1);

    int t2bay = Park.accept(&t2);

    Park.accept(&c3);
    Park.accept(&t1);

    int c4bay = Park.accept(&c4);

    Park.accept(&c5);
    Park.accept(&t5);

    Park.release(t2bay);

    Park.accept(&t4);
    Park.accept(&t3);

    Park.release(c4bay);

    Park.accept(&c2);

    Park.listVehicles();
    return 0;
}