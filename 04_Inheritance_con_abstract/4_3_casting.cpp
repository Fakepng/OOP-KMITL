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

    airplane boing747;
    boing747.model = "747";
    boing747.max_altitude = 13610;

    animal a1 = seagull; // no error
    creature c1 = Sphynx; // no error
    flying_things f1 = boing747; // no error
    
    animal jellyfish = c1;
    flying_things f2 = f1;
    plant p1 = seagull;
    creature c3 = Sphynx;
    creature c4 = c3;


    cout << Sphynx.name << " : " << c1.name << endl;
    cout << boing747.max_altitude << " : " << f1.max_altitude << endl;
    cout << seagull.leg_count << " : " << a1.leg_count << endl;

    cout << seagull.origin << endl;
    cout << a1.origin << endl; // error 'class animal' has no member named 'origin'
    cout << Sphynx.origin << endl; // 'class cat' has no member named 'origin'
    
    animal *p1;
    p1 = &seagull; // assign parent to point child object
    cout << ((bird*)p1)->origin << endl; // no error



    return 0;
}