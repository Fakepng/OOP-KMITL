#include <iostream>
using namespace std;

bool is_prime(long long n){
    for(long long i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

bool is_prime2(long long n){
    for(long long i=2;i<n/2;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int linear_search(int num[],int n,int target){ // return -1 if not found
    for(int i=0;i<n;i++){
        if(num[i] == target){
            return i;
        }
    }
    return -1;
}

int b_search(int num[],int n,int target){
    int lo = 0, hi = n-1;
    int iteration = 0;

    while(hi > lo){
        iteration++;
        int mid = (lo + hi) / 2;
        if(target == num[mid]){
            cout << "b_search iteration: " << iteration << endl;
            return mid;
        }
        else if(num[mid] > target){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    if(target == num[lo]){
        cout << "b_search iteration: " << iteration << endl;
        return lo;
    }

    cout << "b_search iteration: " << iteration << endl;
    return -1;
}

int main(){

    //cout << is_prime(13) << "," << is_prime(14) << "," << is_prime(1299709) << endl;
    //cout << is_prime(179424673) << endl;
    //cout << is_prime(373587883) << endl;
    // cout << is_prime(776531401) << endl;
    //cout << is_prime(2038074743) << endl;
    //cout << is_prime(11111111111) << endl;
    //cout << is_prime(10000000000) << endl;

    //cout << is_prime2(13) << "," << is_prime(14) << "," << is_prime(1299709) << endl;
    //cout << is_prime2(179424673) << endl;
    //cout << is_prime2(373587883) << endl;
    // cout << is_prime2(776531401) << endl;
    //cout << is_prime2(2038074743) << endl;
    //cout << is_prime2(11111111111) << endl;
    //cout << is_prime2(10000000000) << endl;
/*
    int number1[9] = {20,14,12,11,10,4,2,1,0} , n1 = 9;
    int number2[8] = {12,11,10,4,2,1} , n2 = 8;
    int number3[4] = {12,11,10,4} , n3 = 4;

    cout << linear_search(number1,n1,12) << endl;
    cout << b_search(number1,n1,12) << endl;
    cout << linear_search(number2,n2,12) << endl;
    cout << b_search(number2,n2,12) << endl;
    cout << linear_search(number3,n3,13) << endl;
    cout << b_search(number3,n3,13) << endl;
*/

    int number[16] = {20,19,18,17,16,15,14,13,12,11,10,9,4,2,1,0}, n = 16;
    cout << b_search(number,n,-20) << endl;

    return 0;
}