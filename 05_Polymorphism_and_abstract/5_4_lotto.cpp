#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;

class lotto{
    string winner_number;

public :
    void random_number(){ // real psudo random
        winner_number[0] = (rand()%10) + '0';
        winner_number[1] = (rand()%10) + '0';
        winner_number[2] = (rand()%10) + '0';
        winner_number[3] = (rand()%10) + '0';
        winner_number[4] = (rand()%10) + '0';
        winner_number[5] = (rand()%10) + '0';
    }

    void random_number(int fifth_digit, int sixth_digit){ // lock 2 digit random
        random_number();

        if(fifth_digit >= 0) winner_number[4] = fifth_digit + '0';
        if(sixth_digit >= 0) winner_number[5] = sixth_digit + '0';
    }


    void random_number(int forth_digit, int fifth_digit, int sixth_digit){ // lock 3 digit random
        random_number();

        if(forth_digit >= 0) winner_number[3] = forth_digit + '0';
        if(fifth_digit >= 0) winner_number[4] = fifth_digit + '0';
        if(sixth_digit >= 0) winner_number[5] = sixth_digit + '0';
    }

    void print(){
        cout << "winner price is " << winner_number << endl;
    }

    lotto(){
        winner_number = "000000";
    }
};

int main(){

    lotto a;
    a.random_number();
    a.print();
    a.random_number();
    a.print();
    a.random_number(5,5);
    a.print();
    a.random_number(5,5);
    a.print();
    a.random_number(6,6,6);
    a.print();
    a.random_number(6,6,6);
    a.print();
    return 0;
}