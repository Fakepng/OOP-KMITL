#include <iostream>
#include <string>

using namespace std;

class creature{
public :
    string name;
    int x; 

    creature(){
        x = 0;
    }

    virtual void move(int _x){
        x = _x;
        cout << name << " move to position : " << x << endl;
    }
};

class plant : public creature{
public :
    float chlorophyll_rate;

    void move(int _x){
        cout << name << " cannot move" << endl;
    }
};

class animal : public creature{
public :
    int leg_count;

    virtual void move(int _x){
        x = _x;
        cout << name << " using "<< leg_count << " leg(s) move to position : " << x << endl;
    }

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
    void move(int _x){
        x = _x;
        cout << name << " fly to position : " << x << endl;
    }
};

class cat : public animal{
public :
    int cuteness;
    void move(int _x){
        x = _x;
        cout << name << " run to position : " << x << endl;
    }
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

    airplane boing747;
    boing747.model = "747";
    boing747.max_altitude = 13610;

    creature alien;
    alien.name = "alien";

    animal snail;
    snail.name = "snail";
    snail.leg_count = 0;

    plant palm;
    palm.name = "palm";
    palm.chlorophyll_rate = 1.6;

    seagull.move(10);
    Sphynx.move(10);
    //boing747.move(10); error
    alien.move(10);
    snail.move(10);
    palm.move(10);

    return 0;
}