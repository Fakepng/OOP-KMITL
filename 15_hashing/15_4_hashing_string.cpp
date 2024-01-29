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

    hash_row(string k,int v){
        key = k;
        data = v;
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
        table[table_idx] = new hash_row(key,value);       
    }

    void print_key(string key){
        int table_idx = hash_function(key);
        if(table[table_idx] != nullptr){
            cout << key << " -> " << table[table_idx]->data << endl;
        }
    }

    void print_all(){
        for(int i=0;i<100;i++){
            if(table[i] != nullptr){
                cout << i << " -> (" << table[i]->key << "," << table[i]->data << ")" << endl;
            }
        }
    }

};



int main(){

    hash_table places;

    places.insert("pattaya",10);
    places.insert("payak",10);
    places.insert("khonkean",5);
    places.insert("prontera",2000);
    places.insert("Epic center",20);
    places.print_all();

    cout << hash_function("mahasarakham") << endl; //47
    cout << hash_function("khonkean") << endl; //47
    places.insert("mahasarakham",1000);
    places.print_all();

    return 0;
}