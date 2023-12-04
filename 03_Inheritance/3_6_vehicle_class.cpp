#include<iostream>
#include<string>
using namespace std;

class vehicle{
protected :
    int speed;
    int wheel_count;

    vehicle(int wheel){
        wheel_count = wheel;
        speed = 0;
    }

public :
    void print_wheel(){
        cout << "this vehicle has [" <<  wheel_count << "] Wheel(s)" << endl;
    }
};

class motorbike : public vehicle{
public :
    motorbike() : vehicle(2) {

    }

    void print(){
        cout << "motobike is using speed [" << speed << "]Kph" << endl;
    }
};

class airplane : public vehicle{
    int altitude;
public :

    void print(){
        cout << "airplane is at [" << altitude << "] ft above sealevel using speed [" << speed << "]Kph" << endl;
    }

    airplane(int wheel) : vehicle(wheel) {
        altitude = 0;
    }
};

class submarine : public vehicle{
    int depth;
public :

    void print(){
        cout << "submarine is at [" << depth << "] depth level using speed [" << speed << "]Kph" << endl;
    }

    submarine() : vehicle(0) {
        depth = 0;
    }
};

int main(){

    motorbike vespa_sprint;
    airplane a380(22);
    //airplane a340;
    submarine S26T;

    vespa_sprint.print_wheel(); // this vehicle has [2] Wheel(s)
    a380.print_wheel(); // this vehicle has [22] Wheel(s)
    S26T.print_wheel(); // this vehicle has [0] Wheel(s)

    vespa_sprint.print(); // motobike is using speed [0]Kph
    a380.print(); // airplane is at [0] ft above sealevel using speed [0]Kph
    S26T.print(); // submarine is at [0] depth level using speed [0]Kph

    return 0;
}