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

class playlist{
public :

    song* songs[10];
    int song_count = 0;

    playlist(){
        for(int i=0;i<10;i++){
            songs[i] = NULL;
        }
    }

    void add(song *ss){
        song *pp = new song(*ss);
        songs[song_count] = pp;
        song_count++;
    }

    void add(string _name,string _author,int _length, string _brand){
        song *ss = new song(_name, _author, _length, _brand);
        songs[song_count] = ss;
        song_count++;
        //add(ss);
    }

    void remove(){
        if (song_count == 0){
            return;
        }
        songs[--song_count]=NULL;
        delete songs[song_count];
    }

    void play_all(){
        for (int i=0;i<song_count;i++){
            cout << "Play " << songs[i]->get_name() << endl;
        }
        cout << "Play all" <<endl;
    }

    song* get_song(int ii){
        if (ii<0){ 
            cout << "Error less than 0" << endl;
            return NULL;}
        if (ii>=song_count){
            cout << "Error more than song count" << endl;
            return NULL;}
        return songs[ii];
    }

};

int main(){

    song s1("Som San","sek loso",314,"LOSO");
    song s2("Timemachine ","Pond Nipon",328,"Rap");
    song s3("Made in thailand","Yuenyong Opakul",250,"Carabao");
    song s4("Waniphok","Yuenyong Opakul",281,"Carabao");
    song s5("Amerigoey","Yuenyong Opakul",277,"Carabao");
    playlist my_list;

    my_list.add(&s1);
    my_list.add(&s2);
    my_list.play_all();
    my_list.remove();
    my_list.play_all();
    my_list.add(&s2);
    my_list.add(&s3);
    my_list.remove(); my_list.remove(); my_list.remove();
    my_list.add("Lung Kee Mao","Yuenyong Opakul",359,"Carabao");
    my_list.play_all();
    my_list.add(&s4);
    my_list.add(&s5);
    my_list.get_song(1)->play(100);
    my_list.get_song(1)->print_song();
    if(my_list.get_song(4) == NULL){
        cout << "null pointer" << endl;
    }
    else{
        my_list.get_song(4)->print_song();
    }
    my_list.remove();
    my_list.play_all();
    my_list.remove(); my_list.remove(); my_list.remove();
    my_list.remove(); my_list.remove(); my_list.remove();

    /*
    Som San,Timemachine ,
    Som San,
    Lung Kee Mao,
    now we playing Lung Kee Mao of Carabao at 100 sec
    null pointer
    Lung Kee Mao,Waniphok,
*/

    return 0;
}