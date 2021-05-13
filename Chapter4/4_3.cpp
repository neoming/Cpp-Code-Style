#include <stdio.h>
#include <string.h>

class Vehicle
{
    char *plate;
    char *vtype;

public:
    Vehicle(char *vt)
    {
        plate = NULL;
        vtype = vt;
    }

    Vehicle(char *p, char *vt)
    {
        vtype = vt;
        if (p)
        {
            plate = new char[strlen(p) + 1];
            strcpy(plate, p);
        }
        else
        {
            plate = NULL;
        }
    }

    virtual ~Vehicle()
    {
        delete[] plate;
    }

    void identify()
    {
        if (plate)
        {
            printf("%s with plate %s\n", vtype, plate);
        }
        else
        {
            printf("%s with plate <none>\n", vtype);
        }
    }
};

class Car : public Vehicle
{

public:
    Car(char *p = NULL) : Vehicle(p, "car") {}
};

class Truck : public Vehicle
{
public:
    Truck(char *p = NULL) : Vehicle(p, "truck") {}
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