#include<iostream>
#include<string>
using namespace std;

// struct declaration
struct anime{
    string full_name;
    string author;
    int total_episode;
    int length_per_episode; // Average running time in Seconds
};

// function declaration
int total_minuite_calculation(anime a){
    int total_time = a.length_per_episode * a.total_episode;
    return total_time / 60;
}

string anime_name_builder(anime);
void print_anime(anime);

int main(){

    // variable declaration
    anime a1,a2,a3,a4;
    a1.full_name = "The Melancholy of Haruhi Suzumiya";
    a1.author = "Nagaru Tanigawa";
    a1.total_episode = 24;
    a1.length_per_episode = 1200;

    a2.full_name = "One Piece";
    a2.author = "Eiichiro Oda";
    a2.total_episode = 1045; // DEC 18 2022
    a2.length_per_episode = 900;

    a3.full_name = "Demon Slayer: Kimetsu no Yaiba SS1";
    a3.author = "Koyoharu Gotouge";
    a3.total_episode = 26;
    a3.length_per_episode = 1000;

    a4.full_name = "Spy x Family Part 1";
    a4.author = "Tatsuya Endo";
    a4.total_episode = 12;
    a4.length_per_episode = 1440;

    cout << "My anime List in C++" << endl; // print string to STD output using cout
    cout << total_minuite_calculation(a1) << endl; // print object to STD output using cout
    print_anime(a1);
    print_anime(a3);
    print_anime(a2);


    int i = 15498;
    float j = 3.14159265359;
    cout << endl;
    cout << typeid(i).name() << endl; // check type of variable using typeid
    cout << typeid(j).name() << endl;
    cout << typeid(a1).name() << endl;
    cout << typeid(a2).name() << endl;

    // "SHOW" Total running time in (DAY:hour:min) format

    return 0;
}

// function definition 
string anime_name_builder(anime a){
    string out = "";
    string hour = to_string(total_minuite_calculation(a) / 60);
    string min = to_string(total_minuite_calculation(a) % 60);
    out = a.full_name + " by " + a.author + " (" + hour + ":" + min + " hour long)";
    return out;
}

void print_anime(anime a){
    string official_name = anime_name_builder(a);
    cout << official_name << endl;
}

