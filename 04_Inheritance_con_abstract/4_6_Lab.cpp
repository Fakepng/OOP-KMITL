#include<iostream>
#include<string>

using namespace std;

class processor{
public :
    string name;
    string brand;
    float max_speed; // CPU clock speed in Hz unit
    int number_of_thread;

    processor(){ // default constructor

    }

    processor(string n,string b,float s,int t){ // 4 parameter constructor
        name = n;
        brand = b;
        max_speed = s;
        number_of_thread = t;
    }
};

class input_device{
public :
    string name;
    int number_of_button;
    int number_of_multitouch;

    input_device(){

    }

    input_device(string n,int b,int t){
        name = n;
        number_of_button = b;
        number_of_multitouch = t;
    }
};

class computing_device{
public :
    processor cpu;
    float ram_capacity; // RAM capacity in gigabyte
    float storage_capacity; // storage (HDD,SSD) capacity in gigabyte

    float processing_power(){
        return (cpu.number_of_thread * cpu.max_speed) * (ram_capacity * 0.1);
    }
};

class telephone{
public :
    string network;
    float display_size; // display size in inch
    input_device input;

    telephone(){

    }

    telephone(string _network,float _s,input_device _input){
        network = _network;
        display_size = _s;
        input = _input;
    }

    void virtual print(){
        cout << "this phone using [" << network << "] network and using [" << input.name << "] as input " << endl;
    }
};

int main(){
    processor i3("i3-13100","intel",4.5,8);
    processor i5("i5-12500H","intel",4.5,16);
    processor i7("i7-9700K","intel",4.9,8);
    processor ryzen9("Ryzen 9 7900","AMD",5.4,24);
    processor ryzen7("Ryzen 7 7700","AMD",5.3,16);
    processor ryzen5("Ryzen 5 4600H","AMD",4,12);
    processor apple_a4("APL0398","Apple ",0.8,1);
    processor apple_a16("APL1W07","Apple ",2.29,6); // avg speed
    processor SM8150("Qualcomm SM8150 Snapdragon","Qualcomm  ",2.883,6); // avg speed
    processor SM8450("Qualcomm SM8450 Snapdragon","Qualcomm  ",2.5,6); // avg speed

    input_device keyboard("keyboard",200,0);
    input_device nb_keyboard("labtop keyboard",180,0);
    input_device phone_keypad("phone keypad",12,0);
    input_device rotary_dial("Rotary dial",10,0);
    input_device cap_touch("capacitive touch screen",0,5);
    input_device res_touch("resistive touch screen",0,1);

    telephone nokia3310("2G",3,phone_keypad);
    telephone Panasonic_KX_TG("wire",3,phone_keypad);
    telephone vintage_phone("wire",0,rotary_dial);

    labtop alienware_area51("Dell Alienware Area 51",i7,64,nb_keyboard,"windows");
    labtop Hp_Envy("HP Envy 16-h0043TX",i5,16,nb_keyboard,"windows");
    labtop Asus_vivobook("ASUS Vivobook 15 D1502IA",ryzen5,8,nb_keyboard,"Ubuntu");

    alienware_area51.print();
    Hp_Envy.print();
    Asus_vivobook.print();

    //1
    /*
    smartphone iphone4("iPhone 4", apple_a4, 0.512, cap_touch,"3G");
    smartphone iphone12("iPhone 12", apple_a16, 4, cap_touch,"5G");
    iphone4.print();
    iphone12.print();
    */

    //2
    smartphone Samsung_Galaxy_S22("Samsung Galaxy S22", SM8450, 8, cap_touch,"5G");
    smartphone Samsung_Galaxy_Z_flip("Samsung Galaxy Z flip", SM8150, 8, cap_touch,"4G");
    Samsung_Galaxy_S22.print();
    Samsung_Galaxy_Z_flip.print();
   
    /*
    Dell Alienware Area 51 has [250.88] power with [labtop keyboard] input
    HP Envy 16-h0043TX has [115.2] power with [labtop keyboard] input
    ASUS Vivobook 15 D1502IA has [38.4] power with [labtop keyboard] input

    iPhone 4 using [IOS] with [3G] network and running at [0.04096] power
    iPhone 12 using [IOS] with [5G] network and running at [5.496] power
    
    Samsung Galaxy S22 using [Android] with [5G] network and running at [12] power        
    Samsung Galaxy Z flip using [Android] with [4G] network and running at [13.8384] power
    */

}