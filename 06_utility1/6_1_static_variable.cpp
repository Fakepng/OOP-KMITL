#include<iostream>
using namespace std;

class sound{
public :
    static int playing_limit;
    static int playing_count;
    static int sound_count;

    string name;
    int length; // length in sec
    bool is_playing = false;

    static void print(){
        cout << "total sound is : [" << sound_count << "] now playing [" << playing_count << "]" << endl;
    }

    static int get_playing_count(){
        return playing_count;
    }

    static int get_sound_count(){
        return sound_count;
    }
/*
    void play(){
        if(is_playing == true){
            cout << name << " is still playing " << endl;
            return;
        }
        
        is_playing = true;
        playing_count++;
        cout << "playing " << name << endl;
    }
*/

    void play(){
        if(is_playing == true){
            cout << name << " is still playing " << endl;
            return;
        }

        if(playing_count >= playing_limit){
            cout << "playlist is full, can't play " << name << endl;
        }
        else{
            is_playing = true;
            playing_count++;
            cout << "playing " << name << endl;
        }
    }

    void stop(){
        if(is_playing == false){
            cout << name << " is not playing " << endl;
        }
        else{
            is_playing = false;
            playing_count--;
        }
    }

    sound(string _name){
        name = _name;
        sound_count++;
        cout << "this sound number : " << sound_count << endl;
    }

    ~sound(){
        sound_count--;
        cout << "current sound count : " << sound_count << endl;
    }
};

int sound::sound_count = 0; // init
int sound::playing_count = 0; // init
int sound::playing_limit = 4; // init

int main(){

    //sound::sound_count++;
    cout << sound::sound_count << endl;
    sound s1("Som san");
    sound s2("Jai sang ma");
    sound s3("s3");
    if(true){
        sound s7("555");
    }
    sound s4("s4");
    sound s5("s5");
    sound s6("s6");
    cout << sound::sound_count << endl;
    
    cout << sound::playing_count << endl;
    s1.play(); // playing Som san
    s2.play(); // playing Jai sang ma
    s3.play(); // playing s3
    s4.play(); // playing s4
    s5.play(); // playlist is full, can't play s5
    s6.play(); // playlist is full, can't play s6
    s1.stop(); 
    s6.play(); // playing s6
    s1.stop(); // Som san is not playing
    s2.stop();
    s2.stop(); // Jai sang ma is not playing
    cout << sound::playing_count << endl; // 3
    sound::print();

    sound::print();

    return 0;
}