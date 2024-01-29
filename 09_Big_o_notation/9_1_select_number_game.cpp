#include <iostream>
using namespace std;

int brute_fource_select(int num[],int n){
    int iteration = 0;
    int max = (((num[0] * num[1]) + num[2]) - num[3]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                for(int l=0;l<n;l++){
                    iteration++;
                    if(i!=j && i!=k && i!= l && j!=k && j!=l && k!= l){
                        //cout << num[j] << " " << num[k] << " " << num[l] << " " << num[i] << endl;
                        int result = (((num[i] * num[j]) + num[k]) - num[l]);
                        if(result > max){
                            max = result;
                        }
                    }
                }
            }
        }
    }

    cout << "brute_fource_select iteration: " << iteration << endl;
    return max;
}

int fix_minmum_select(int num[],int n){
    int max = (((num[0] * num[1]) + num[2]) - num[n-1]);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            for(int k=0;k<n-1;k++){
                if(i!=j && i!=k && j!=k){
                    int result = (((num[i] * num[j]) + num[k]) - num[n-1]);
                    if(result > max){
                        max = result;
                    }
                }
            }
        }
    }
    return max;
}

int greedy_select(int num[],int n){
    return ((num[0] * num[1]) + num[2]) - num[n-1];
}

int linear_search(int num[],int n,int target){ // return -1 if not found
    for(int i=0;i<n;i++){
        if(num[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){

    int number1[7] = {12,11,10,4,2,1,0} , n1 = 7;
    int number2[5] = {9,8,7,6} , n2 = 4;

    cout << brute_fource_select(number1,n1) << endl;
    cout << brute_fource_select(number2,n2) << endl;

    //cout << fix_minmum_select(number1,n1) << endl;
    //cout << fix_minmum_select(number2,n2) << endl;

    //cout << greedy_select(number1,n1) << endl;
    //cout << greedy_select(number2,n2) << endl;
/*
    cout << linear_search(number1,n1,1) << endl;
    cout << linear_search(number1,n1,12) << endl;
    cout << linear_search(number1,n1,999) << endl;
*/
    //int number3[1000] = {10000,9990,9980,9970,9970...};

    int number3[300] , n3 = 300; // 10000,9990,9980,9970,9970...
    for(int i=1;i<=300;i++){
        number3[300 - i] = i * 10;
    }

    // cout << greedy_select(number3,n3) << endl;
    // cout << fix_minmum_select(number3,n3) << endl;
    // cout << brute_fource_select(number3,n3) << endl;

    return 0;
}