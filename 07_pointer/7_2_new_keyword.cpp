#include<iostream>
#include<string>
using namespace std;

class media{
private :
    int playing_sec; // last played seconds in episode

protected :
    string name;
    string author;
    int length; // media length in Seconds

public :
    void play(int time){ // play method
        int remaining_time = length - playing_sec;
        //cout << "Playing " << name << " at[" << playing_sec <<"] : [" << remaining_time <<" sec] remaining" << endl;
        if(time > remaining_time){            
            playing_sec = 0;
        }
        else{
            playing_sec += time;
        }       
    }

    string get_name(){
        return name;
    }

    int get_playing_sec(){
        return playing_sec;
    }

    void reset(){
        playing_sec = 0;
    }

    media(){ // default constructor
        name = "unknow";
        length = 0;
        playing_sec = 0;
    }

    media(string _name,string _author,int _length){ // 3 parameter constructor
        name = _name;
        author = _author;
        length = _length;
        playing_sec = 0;
    }

};

class song : public media{
private :
    string brand;

public :
    song(){ // default constructor
    }

    song(string _name,string _author,int _length, string _brand) : media(_name,_author,_length){ // 4 parameter constructor
        brand = _brand;
    }

    void print_song(){
        cout << "now we playing " << name << " of " << brand << " at " <<  get_playing_sec() << " sec" << endl;
    }

    void stop_song(){
        reset();
        cout << name << " has stopped" << endl;
    }

    ~song(){
        cout << name << " has delete" << endl; 
    }
};

int main(){

    song s1("Som San","sek loso",314,"LOSO");
    song s2("Timemachine ","Pond Nipon",328,"Rap");
    
    song *p1,*p2;
    p1 = &s1;
    p2 = &s2;

    s1.play(1);
    s2.play(2);
    p1->play(4);
    p2->play(8);

    cout << s1.get_playing_sec() << "," << s2.get_playing_sec() << endl;

    p1 = new song("Lung Kee Mao","Yuenyong Opakul",359,"Carabao");

    p1->play(16);
    p1->print_song();
    // now we playing Lung Kee Mao of Carabao at 16 sec

    delete p1;
    p1 = NULL;
    //p1->play(32); // crash!
    //p1->print_song(); // crash!

    if(p1 == NULL){
        cout << "no object" << endl;
    }
    else{
        cout << "object name : " << p1->get_name() << endl;
    }

    return 0;
}