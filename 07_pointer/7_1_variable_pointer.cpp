#include<iostream>
#include<string>
using namespace std;

// struct declaration
struct anime{
private :
    int playing_episode; // last played episode
    int playing_sec; // last played seconds in episode

public :
    string full_name;
    string author;
    int total_episode;
    int length_per_episode; // Average running time in Seconds

    void play(int time){ // play method
        int remaining_time = length_per_episode - playing_sec;
        if(time > remaining_time){ // next ep
            //cout << "playing " << full_name << " EP." << playing_episode <<" [" << remaining_time <<" sec]" << endl;
            playing_episode++;
            if(playing_episode >= total_episode){
                playing_episode = 1;
            }
            playing_sec = 0;
        }
        else{
            //cout << "playing " << full_name << " EP." << playing_episode <<" [" << time <<" sec]" << endl;
            playing_sec += time;
        }
    }

    void select_episode(int _ep){
        if(_ep <= 0) return;
        if(_ep > total_episode) return;

        playing_episode = _ep;
        playing_sec = 0;
    }

    anime(){
        //cout << "this is default constructor" << endl;

        playing_episode = 1;
        playing_sec = 0;
    }

    anime(string _name,string _author,int _ep,int length){
        //cout << "this is constructor for " << _name << endl;

        full_name = _name;
        author = _author;
        total_episode = _ep;
        length_per_episode = length;

        playing_episode = 1;
        playing_sec = 0;
    }

    ~anime(){
        //cout << full_name << " has destroyed" << endl;
    }

};

int calculate_text_size(string _text){
    return _text.length();
}

void add_episode(anime a){
    a.total_episode++;
}

void add_episode(anime *a){
    a->total_episode++;
}

int main(){

    // variable declaration
    anime a1("The Melancholy of Haruhi Suzumiya","Nagaru Tanigawa",24,1200);   
    anime a2("Spy x Family Part 1","Tatsuya Endo",1440,1200);  
    anime a3("detective conan","Gosho Aoyama",12,1067);
    anime a4("The Legend of Muay Thai: 9 Satra","Pongsa Kornsri",1,6120);
    anime a5("k-on season1","Kakifly",12,1440);  

    // pointer declaration
    anime o,*p,q,r,*s;
    anime* t,u;
    p = &a1;
    o = a1;
    cout << a1.full_name << endl;
    cout << o.full_name << endl;
    cout << calculate_text_size(o.full_name) << endl;
    cout << calculate_text_size(p->full_name) << endl;

    int *pa,*pb,*pc;
    int aa = 2,bb = 3,cc =4;
    pa = &aa;
    pb = &bb;
    pc = &cc;

    anime *p1,*p2,*p3,*p4;
    p1 = &a1;
    p3 = &a1;
    p2 = &a2;
    p4 = &a4;

    cout << a1.total_episode << " "; // 24
    cout << o.total_episode << " "; // 24
    cout << p->total_episode << endl;

    a1.total_episode++;
    o.total_episode++;
    p->total_episode++;

    cout << a1.total_episode << " "; // 26
    cout << o.total_episode << " "; // 25
    cout << p->total_episode << endl; // 26

    add_episode(a1);
    add_episode(a1);
    add_episode(&o);
    add_episode(p);
    add_episode(o);
    add_episode(o);

    cout << a1.total_episode << " "; // 27
    cout << o.total_episode << " "; //28
    cout << p->total_episode << endl; //27

    return 0;
}
