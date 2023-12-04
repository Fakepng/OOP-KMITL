#include<iostream>
#include<string>
using namespace std;

// struct declaration
struct anime{
    string full_name;
    string author;
    int total_episode;
    int length_per_episode; // Average running time in Seconds

    int playing_episode; // last played episode
    int playing_sec; // last played seconds in episode

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

    anime(){
        cout << "this is default constructor" << endl;

        playing_episode = 1;
        playing_sec = 0;
    }

    anime(string _name,string _author,int _ep,int length){ // 4 parameter function
        cout << "this is constructor for " << _name << endl;

        full_name = _name;
        author = author;
        total_episode = _ep;
        length_per_episode = length;

        playing_episode = 1;
        playing_sec = 0;
    }

};

int main(){

    // variable declaration
    anime a1("The Melancholy of Haruhi Suzumiya","Nagaru Tanigawa",24,1200);

    anime a2;
    a2.full_name = "Spy x Family Part 1";
    a2.author = "Tatsuya Endo";
    a2.total_episode = 12;
    a2.length_per_episode = 1440;  

    /*
    cout << a1.playing_episode << endl;
    cout << a2.playing_episode << endl;
*/

    a1.play(500);      // playing The Melancholy of Haruhi Suzumiya EP.1 [500 sec] 
    a1.play(500);      // playing The Melancholy of Haruhi Suzumiya EP.1 [500 sec]
    a1.play(99999);    // playing The Melancholy of Haruhi Suzumiya EP.1 [700 sec] 
    a1.play(99999);    // playing The Melancholy of Haruhi Suzumiya EP.2 [1200 sec]
    a2.play(100);      // playing Spy x Family Part 1 EP.1 [100 sec]
    a2.play(100);      // playing Spy x Family Part 1 EP.1 [100 sec]
    a2.play(100);      // playing Spy x Family Part 1 EP.1 [100 sec]
    a2.play(99999);    // playing Spy x Family Part 1 EP.1 [1140 sec]
    a1.play(500);      // playing The Melancholy of Haruhi Suzumiya EP.3 [500 sec]
    a1.play(99999);    // playing The Melancholy of Haruhi Suzumiya EP.3 [700 sec]

    return 0;
}
