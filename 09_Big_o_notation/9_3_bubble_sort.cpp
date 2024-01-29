#include <iostream>
using namespace std;

int main(){

    // int number2[9] = {8,17,16,5,9,7,1,3,2};
    // int number2[8] = {1,2,3,4,5,6,7,8};
    // int number2[4] = {1,2,3,4};
    int number2[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    // int number2[16] = {16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int number1[9] = {8,17,16,5,9,7,1,3,2};
    // int number2[16] = {20,21,23,24,25,26,27,28,29};
    int number3[16] = {16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int n = 16;

    int m1=0,m2=0,m3=0;

    // normal bubble sort
    for(int i=0;i<n - 1;i++){
        for(int j=0;j<(n-i)-1;j++){
            m1++;
            if(number1[j] > number1[j + 1]){
                int tmp = number1[j];
                number1[j] = number1[j+1];
                number1[j+1] = tmp;
            }
        }
    }

    // n*n bubble sort
    for(int i=0;i<n - 1;i++){
        for(int j=0;j<n-1;j++){
            m2++;
            if(number2[j] > number2[j + 1]){
                int tmp = number2[j];
                number2[j] = number2[j+1];
                number2[j+1] = tmp;
            }
        }
    }

    //limited bubble sort
    for(int i=0;i<n - 1;i++){
        bool swaped = false;
        for(int j=0;j<n-1;j++){
            m3++;
            if(number3[j] > number3[j + 1]){
                swaped = true;
                int tmp = number3[j];
                number3[j] = number3[j+1];
                number3[j+1] = tmp;
            }
        }
        if(swaped == false) break;
    }

    // for(int i=0;i<n;i++){
    //     cout << number1[i] << " " ;
    // }
    // cout << " by " << m1 << endl;

    for(int i=0;i<n;i++){
        cout << number2[i] << " " ;
    }
    cout << " by " << m2 << endl;

    // for(int i=0;i<n;i++){
    //     cout << number3[i] << " " ;
    // }
    // cout << " by " << m3 << endl;

    return 0;
}