#include<iostream>
#include<string>
using namespace std;

class media{
public :
    int playing_sec; // last played seconds in episode

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

        cout << "default constructor of [media] class" << endl;

        name = "unknow";
        length = 0;
        playing_sec = 0;
    }

    media(string _name,string _author,int _length){ // 3 parameter constructor

        cout << "3 parameter constructor of [media] class" << endl;

        name = _name;
        author = _author;
        length = _length;
        playing_sec = 0;
    }

};

class song : public media{
public :
    string brand;

    song(){ // default constructor
        cout << "default constructor of [song] class" << endl;
    }


    song(string _name,string _author,int _length, string _brand) : media(_name,_author,_length){ // 4 parameter constructor
        
        cout << "4 parameter constructor of [song] class" << endl;
        brand = _brand;
        //media(_name,_author,_length); // call base constructor
    
        /*
        name = _name;
        author = _author;
        length = _length;
        playing_sec = 0;
        brand = _brand;
        */
    }
};

class movie : public media{
public :
    string director;
    string main_actor;

    movie(){
        cout << "default constructor of [movie] class" << endl;
    }

    movie(string _name,string _author,int _length, string _director, string _actor) : media(_name,_author,_length){ // 5 parameter constructor
        cout << "5 parameter constructor of [movie] class" << endl;
        
        //media(_name,_author,_length);
        //name = _name;
        //author = _author;
        //length = _length;
        director = _director;
        main_actor = _actor;
    }
};

class episode : public media{
public :
    int episode_number;
    string episode_name;

    episode(){
        cout << "default constructor of [episode] class" << endl;
    }

    episode(string _name,string _author,int _length, int ep_num, string ep_name) : media(_name,_author,_length){ // 5 parameter constructor
        cout << "5 parameter constructor of [episode] class" << endl;
        episode_number = ep_num;
        episode_name = ep_name;
    }
};

int main(){

    
    
    //cout << s1.name << endl;
    //cout << s1.author << endl;
    //cout << s1.length << endl;
    //cout << s1.brand << endl;
    media ttt;
    cout << endl;
    song s2("Timemachine ","Pond Nipon",328,"Rap");
    cout << endl;
    movie m1("The Disappearance of Haruhi Suzumiya","Nagaru Tanigawa",9707,"Tatsuya Ishihara","Haruhi");
    movie m2("Avatar","James Cameron",9720,"James Cameron","Sam Worthington");
    episode e1("Thi da Satan : ep 3 Earth Water Wind Fire","Kantana",3600,3,"Earth Water Wind Fire");
    episode e2("Start-Up (2020) : ep 16 Scale up","Studio Dragon",4800,16,"Scale up");
    cout << m2.name << " " << m2.author << endl;

    m1.play(40);
    s2.play(30);

    return 0;
}