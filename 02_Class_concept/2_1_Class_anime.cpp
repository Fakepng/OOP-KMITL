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
};

// function declaration
void play(anime*,int);

int main(){

    // variable declaration
    anime a1,a2;
    a1.full_name = "The Melancholy of Haruhi Suzumiya";
    a1.author = "Nagaru Tanigawa";
    a1.total_episode = 24;
    a1.length_per_episode = 1200;
    a1.playing_episode = 1;
    a1.playing_sec = 0;

    a2.full_name = "Spy x Family Part 1";
    a2.author = "Tatsuya Endo";
    a2.total_episode = 12;
    a2.length_per_episode = 1440;  
    a2.playing_episode = 1;
    a2.playing_sec = 0;

    play(&a1,500);      // playing The Melancholy of Haruhi Suzumiya EP.1 [500 sec]
    play(&a1,99999);    // playing The Melancholy of Haruhi Suzumiya EP.1 [700 sec] 
    play(&a1,99999);    // playing The Melancholy of Haruhi Suzumiya EP.2 [1200 sec]
    play(&a2,100);      // playing Spy x Family Part 1 EP.1 [100 sec]
    play(&a2,100);      // playing Spy x Family Part 1 EP.1 [100 sec]
    play(&a2,100);      // playing Spy x Family Part 1 EP.1 [100 sec]
    play(&a2,99999);    // playing Spy x Family Part 1 EP.1 [1140 sec]
    play(&a1,500);      // playing The Melancholy of Haruhi Suzumiya EP.3 [500 sec]
    play(&a1,99999);    // playing The Melancholy of Haruhi Suzumiya EP.3 [700 sec]

    return 0;
}

// function definition
void play(anime *a,int time){
    int remaining_time = a->length_per_episode - a->playing_sec;
    if(time > remaining_time){ // next ep
        cout << "playing " << a->full_name << " EP." << a->playing_episode <<" [" << remaining_time <<" sec]" << endl;
        a->playing_episode++;
        if(a->playing_episode >= a->total_episode){
            a->playing_episode = 1;
        }
        a->playing_sec = 0;
    }
    else{
        cout << "playing " << a->full_name << " EP." << a->playing_episode <<" [" << time <<" sec]" << endl;
        a->playing_sec += time;
    }
}
