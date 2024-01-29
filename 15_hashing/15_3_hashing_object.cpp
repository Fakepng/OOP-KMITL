#include<iostream>
using namespace std;

int hash_function(int in){
    return (in%100);
}

class hash_row{ // hash tuple, hash node
public :
    int key;
    int data;

    hash_row(int k,int v){
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

    void insert(int key,int value){
        int table_idx = hash_function(key);
        table[table_idx] = new hash_row(key,value);       
    }

    void increase(int key){
        int table_idx = hash_function(key);
        if(table[table_idx] == nullptr){
            table[table_idx] = new hash_row(key,1);  
        }
        else{
            table[table_idx]->data++;
        }
    }

    void print_key(int key){
        int table_idx = hash_function(key);
        if(table[table_idx] != nullptr){
            cout << key << " -> " << table[table_idx]->data << endl;
        }
    }

    void print_all(){
        for(int i=0;i<100;i++){
            int table_idx = hash_function(i);
            if(table[table_idx] != nullptr){
                cout << i << " -> " << table[table_idx]->data << endl;
            }
        }
    }

};



int main(){

    hash_table lotto;
    /*
    lotto.insert(00,2);
    lotto.insert(01,3);
    lotto.insert(03,1);
    lotto.insert(89654,2);
    */

    lotto.increase(00);
    lotto.increase(00);
    lotto.increase(01);
    lotto.increase(01);
    lotto.increase(01);
    lotto.increase(03);
    lotto.increase(89654);
    lotto.increase(89654);

    lotto.print_all();
    cout << endl;
    lotto.print_key(89654);

    return 0;
}