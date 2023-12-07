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
            cout << "playing " << full_name << " EP." << playing_episode <<" [" << remaining_time <<" sec]" << endl;
            playing_episode++;
            if(playing_episode >= total_episode){
                playing_episode = 1;
            }
            playing_sec = 0;
        }
        else{
            cout << "playing " << full_name << " EP." << playing_episode <<" [" << time <<" sec]" << endl;
            playing_sec += time;
        }
    }

    void select_episode(int _ep){
        if(_ep <= 0) return;
        if(_ep > total_episode) return;

        playing_episode = _ep;
        playing_sec = 0;
    }

    void select_time(int _time) {
        if(_time < 0) {
            playing_sec = 0;
            return;
        };
        if(_time > length_per_episode) {
            playing_sec = 0;
            return;
        };

        playing_sec = _time;
    }

    anime(){
        cout << "this is default constructor" << endl;

        playing_episode = 1;
        playing_sec = 0;
    }

    anime(string _name, string _author, int _length) {
      anime(_name, _author, 12, _length);
    }

    anime(string _name,string _author,int _ep,int length){
        cout << "this is constructor for " << _name << endl;

        full_name = _name;
        author = _author;
        total_episode = _ep;
        length_per_episode = length;

        playing_episode = 1;
        playing_sec = 0;
    }

    ~anime(){
        cout << full_name << " has destroyed" << endl;
        cout << playing_episode << " episode has played" << endl;
    }

};

int main(){

    // variable declaration
    anime a1("The Melancholy of Haruhi Suzumiya","Nagaru Tanigawa",24,1200);   
    anime a2("Spy x Family Part 1","Tatsuya Endo",1440);  
    {
        anime a3("detective conan","Gosho Aoyama",1067,1200);
        anime a4("The Legend of Muay Thai: 9 Satra","Pongsa Kornsri",1,6120);
        a4.play(99999);
        a4.play(99999);
    }
    anime a5("k-on season1","Kakifly",1440);  

    a1.play(20);
    a2.play(99999);
    a2.play(30);

    a5.select_episode(0);
    a5.play(10);

    a5.select_episode(13);
    a5.select_time(1300);
    a5.play(200);
    a5.play(200);

    a2.select_time(-1);
    a2.play(10);
    a2.select_time(2);
    a2.play(99999);

    /* Expected
    this is constructor for The Melancholy of Haruhi Suzumiya
    this is constructor for Spy x Family Part 1
    this is constructor for detective conan
    this is constructor for The Legend of Muay Thai: 9 Satra
    playing The Legend of Muay Thai: 9 Satra EP.1 [6120 sec]
    playing The Legend of Muay Thai: 9 Satra EP.1 [6120 sec]
    The Legend of Muay Thai: 9 Satra[0] episode remaining
    detective conan[1066] episode remaining
    this is constructor for k-on season1
    playing The Melancholy of Haruhi Suzumiya EP.1 [20 sec]
    playing Spy x Family Part 1 EP.1 [1440 sec]
    playing Spy x Family Part 1 EP.2 [30 sec]
    playing k-on season1 EP.1 [10 sec]
    playing k-on season1 EP.1 [140 sec]
    playing k-on season1 EP.2 [200 sec]
    playing Spy x Family Part 1 EP.2 [10 sec]
    playing Spy x Family Part 1 EP.2 [1438 sec]
    k-on season1[10] episode remaining
    Spy x Family Part 1[9] episode remaining
    The Melancholy of Haruhi Suzumiya[23] episode remaining
    */

    return 0;
}
