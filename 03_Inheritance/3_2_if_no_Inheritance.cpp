#include<iostream>
#include<string>
using namespace std;

class media{ // parent
private :
    int playing_sec; // last played seconds in episode

protected :
    string name;
    string author;
    int length; // media length in Seconds

public :
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

class song{
private :
    int playing_sec; // last played seconds in episode

public :
    string name;
    string author;
    string brand; // added from media
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

    song(){ // default constructor
        name = "unknow";
        length = 0;
        playing_sec = 0;
    }

    song(string _name,string _author,int _length){ // 3 parameter constructor
        name = _name;
        author = _author;
        length = _length;
        playing_sec = 0;
    }

};

class movie{
private :
    int playing_sec; // last played seconds in episode

public :
    string name;
    string author;
    string director;
    string main_actor;
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

    movie(){ // default constructor
        name = "unknow";
        length = 0;
        playing_sec = 0;
    }

    movie(string _name,string _author,int _length){ // 3 parameter constructor
        name = _name;
        author = _author;
        length = _length;
        playing_sec = 0;
    }

};

class episode {
private :
    int playing_sec; // last played seconds in episode

public :
    string name;
    string author;
    int episode_number;
    string episode_name;
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

    episode(){ // default constructor
        name = "unknow";
        length = 0;
        playing_sec = 0;
    }

    episode(string _name,string _author,int _length){ // 3 parameter constructor
        name = _name;
        author = _author;
        length = _length;
        playing_sec = 0;
    }

};

int main(){

    media s1("Som San","sek loso",314);
    media s2("Timemachine ","Pond Nipon",328);
    media m1("The Disappearance of Haruhi Suzumiya","Nagaru Tanigawa",9707);
    media m2("Avatar","James Cameron",9720);
    media e1("Thi da Satan : ep 3 Earth Water Wind Fire","Kantana",3600);
    media e2("Start-Up (2020) : ep 16 Scale up","Studio Dragon",4800);

    song s1("Som San","sek loso",314,"SEK LOSO");

    s1.play(200);
    s1.play(200);   
    s1.play(200); 

    return 0;
}