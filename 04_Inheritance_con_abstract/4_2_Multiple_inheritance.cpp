#include <iostream>
#include <string>

using namespace std;

class creature{
public :
    string name;
};

class plant : public creature{
public :
    float chlorophyll_rate;
};

class animal : public creature{
public :
    int leg_count;
};

class flying_things{
public :
    int max_altitude;
};

class airplane : public flying_things{
public :
    string model;
};

class bird : public animal, public flying_things{
public :
    string origin;
};

class cat : public animal{
public :
    int cuteness;
};

int main(){

    bird seagull;
    seagull.name = "seagull";
    seagull.leg_count = 2;
    seagull.max_altitude = 100; // 100 meter
    seagull.origin = "Australia";

    cat Sphynx;
    Sphynx.name = "Sphynx";
    Sphynx.leg_count = 4;
    Sphynx.cuteness = -10;

    int i = -99;
    float fff = -0.111;
    i = fff;
    fff = i;

    animal a = Sphynx;
    creature c = Sphynx;
    creature b;

    









/*
    animal a;
    cat mf;
    a = Sphynx;

    mf = a;
*/
    return 0;
}