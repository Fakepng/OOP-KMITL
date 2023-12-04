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
        cout << "Playing " << name << " at[" << playing_sec <<"] : [" << remaining_time <<" sec] remaining" << endl;
        if(time > remaining_time){            
            playing_sec = 0;
        }
        else{
            playing_sec += time;
        }       
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

        name = "aaa";

    }

    void print_song(){
        cout << "now we playing " << name << " of " << brand << " at " <<  get_playing_sec() << " sec" << endl;
    }

    void stop_song(){
        reset();
        cout << name << " has stopped" << endl;
    }
};

class movie : public media{
private :
    string director;
    string main_actor;

public :
    movie(){ // default constructor
    }

    movie(string _name,string _author,int _length, string _director, string _actor) : media(_name,_author,_length){ // 5 parameter constructor
        director = _director;
        main_actor = _actor;
    }
};

class episode : public media{
private :
    int episode_number;
    string episode_name;

public :
    episode(){ // default constructor
        episode_number = -1;
    }

    episode(string _name,string _author,int _length, int ep_num, string ep_name) : media(_name,_author,_length){ // 5 parameter constructor
        episode_number = ep_num;
        episode_name = ep_name;
    }
};

int main(){
    media i1;
    i1.play(100);


    song s1("Som San","sek loso",314,"LOSO");
    song s2("Timemachine ","Pond Nipon",328,"Rap");
    movie m1("The Disappearance of Haruhi Suzumiya","Nagaru Tanigawa",9707,"Tatsuya Ishihara","Haruhi");
    movie m2("Avatar","James Cameron",9720,"James Cameron","Sam Worthington");
    episode e1("Thi da Satan : ep 3 Earth Water Wind Fire","Kantana",3600,3,"Earth Water Wind Fire");
    episode e2("Start-Up (2020) : ep 16 Scale up","Studio Dragon",4800,16,"Scale up");


    s1.play(50);
    s1.print_song();
    s1.stop_song();
    s1.play(50);

    s1.reset();


    return 0;
}