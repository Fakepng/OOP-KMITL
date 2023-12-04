#include <iostream>
#include <string>
using namespace std;

class car{

    string name;
    float acceleration;
    float deceleration;
    float speed;

public :

    car(){
        name = "unknow";
        acceleration = 1;
        deceleration = 2.5;
        speed = 0;
    }

    car(string n,float a){
        name = n;
        acceleration = a;
        deceleration = 2.5;
        speed = 0;
    }

    car(string n,float a, float b){
        name = n;
        acceleration = a;
        deceleration = b;
        speed = 0;
    }



    void print(){
        cout << name << " is at [" << speed << "] m/s" << endl;
    }

    void speed_up(){
        speed += acceleration;
    }

    void speed_down(){
        speed -= deceleration;
        if(speed < 0){
            speed = 0;
        }
    }

};

int main(){

    car c1("ae86",1.5);
    car c2;
    car c3("Honda wave",0.2);
    car c4("tesla model X",9.92,100);

    cout << "speeding up" << endl;
    for(int i=0;i<10;i++){
        c1.speed_up(); c2.speed_up(); c3.speed_up(); c4.speed_up();
    }

    c1.print(); c2.print(); c3.print(); c4.print();

    cout << "slowing down" << endl;
    c1.speed_down(); c2.speed_down(); c3.speed_down(); c4.speed_down();

    c1.print(); c2.print(); c3.print(); c4.print();

    return 0;
}