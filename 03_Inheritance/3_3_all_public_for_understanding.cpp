#include<iostream>
#include<string>
using namespace std;

class media{
private :
    int playing_sec; // last played seconds in episode

public :
    string name;
    string author;
    int length; // media length in Seconds


    void play(int time){ // play method
        int remaining_time = length - playing_sec;
        cout << "Playing " << name << " at[" << playing_sec <<"] : [" << remaining_time <<" sec] remaining" << endl;
        if(time > remaining_time){            
            playing_sec = 0;
        }
        else{
            playing_sec += time;
        }       
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
public :
    string brand;
};

class movie : public media{
public :
    string director;
    string main_actor;
};

class episode : public media{
public :
    int episode_number;
    string episode_name;
};

int main(){
/*
    media s1("Som San","sek loso",314);
    media s2("Timemachine ","Pond Nipon",328);
    media m1("The Disappearance of Haruhi Suzumiya","Nagaru Tanigawa",9707);
    media m2("Avatar","James Cameron",9720);
    media e1("Thi da Satan : ep 3 Earth Water Wind Fire","Kantana",3600);
    media e2("Start-Up (2020) : ep 16 Scale up","Studio Dragon",4800);
*/

    song s1;
    s1.name = "Som San";
    s1.author = "sek loso";
    s1.length = 314;
    s1.brand = "LOSO";
    s1.playing_sec = -5;
    s1.play(10);

    movie m1;
    m1.name = "Avatar";
    m1.author = "James Cameron";
    m1.length = 9720;
    m1.director = "James Cameron";;
    m1.main_actor = "Sam Worthington";
    m1.play(20);

    episode e1;
    e1.name = "Thi da Satan : ep 3 Earth Water Wind Fire";
    e1.author = "Kantana";
    e1.length = 4800;
    e1.episode_number = 3;
    e1.episode_name = "Earth Water Wind Fire";
    e1.play(30);

    return 0;
}