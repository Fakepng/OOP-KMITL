#include<iostream>
#include<string>
using namespace std;

class vehicle{
protected :
    int speed;
    int wheel_count;
    vehicle(int wheel){
        wheel_count = wheel;
    }
public :
    void print_wheel(){
        cout << "this vehicle has [" <<  wheel_count << "] Wheel(s)" << endl;
    }

    void virtual print() = 0;
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
        cout << "airplane is at [" << altitude << "] ft above sea level using speed [" << speed << "]Kph" << endl;
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

    motorbike vaspa_sprint;
    airplane a380(22);
    airplane a777(14);
    submarine S26T;
    //motorbike honda_wave;

    vehicle* my_vehicles[4];
    my_vehicles[0] = &vaspa_sprint;
    my_vehicles[1] = &a380;
    my_vehicles[2] = &a777;
    my_vehicles[3] = &S26T;

    for(int i=0;i<4;i++){
        my_vehicles[i]->print();
    }

    return 0;
}