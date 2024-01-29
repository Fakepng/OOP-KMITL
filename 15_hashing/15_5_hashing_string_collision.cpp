#include<iostream>
using namespace std;

int hash_function(string in){
    int sum = 0;
    for(int i=0;i<in.size();i++){
        sum += in[i];
    }
    return (sum%100);
}

class hash_row{ // hash tuple, hash node
public :
    string key;
    int data;
    hash_row* next;

    hash_row(string k,int v){
        key = k;
        data = v;
        next = nullptr;
    }
};

class hash_table{
    hash_row* table[100];

public :
    hash_table(){
        for(int i=0;i<100;i++){ // init table
            table[i] = nullptr;
        }
    }

    void insert(string key,int value){
        int table_idx = hash_function(key);
        hash_row** p = &table[table_idx];
        while(*p != nullptr){ // go to last link
            if((*p)->key == key){ // override key
                (*p)->data = value;
                return;
            }
            p = &((*p)->next);
        }     
        (*p) = new hash_row(key,value);  
    }

    void print_key(string key){
        hash_row** p = &table[hash_function(key)];
         while((*p) != nullptr){
            if(key == (*p)->key){
                cout << (*p)->key << "->" << (*p)->data << endl;
                return;
            }
            else{
                p = &((*p)->next);
            }         
        }
        cout << "Not found key [" << key <<"]";     
    }

    void print_all(){
        for(int i=0;i<100;i++){
            hash_row** p = &table[i];
            if((*p) != nullptr){
                cout << i;
                while((*p) != nullptr){
                    cout << " -> (" << (*p)->key << "," << (*p)->data << ") " ;
                    p = &((*p)->next);
                }
                cout << endl;
            }          
        }
    }

};



int main(){

    hash_table places;


    places.insert("mahasarakham",10);
    places.insert("khonkean",15);

    places.insert("pattaya",200);
    places.insert("payak",30);
    places.insert("prontera",2000);
    places.insert("Epic center",20);

    //places.print_all();

    places.print_key("pattaya");
    places.print_key("mahasarakham");
    places.print_key("khonkean");




    return 0;
}