#include<iostream>
using namespace std;

template <typename T> void selection_sort(T a[],int n){
    for(int i=0;i<n;i++){
        int min_idx = i;
        for(int j=i;j<n;j++){
            if(a[j] < a[min_idx]){
                min_idx = j;
            }
        }
        T tmp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = tmp;
    }
}

template <typename T> void print_array(T a[],int n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){

    int my_int[] = {5,6,8,4,1,3,9,11,2};
    char my_char[] = {'e','a','i','u','o'};
    double my_double[] = {5.3,6.4,8.3,6.5,9.3,4.4,1.2,2.6};

    selection_sort<int>(my_int,sizeof(my_int)/sizeof(int));
    print_array<int>(my_int,sizeof(my_int)/sizeof(int));

    selection_sort<char>(my_char,sizeof(my_char)/sizeof(char));
    print_array<char>(my_char,sizeof(my_char)/sizeof(char));

    selection_sort<double>(my_double,sizeof(my_double)/sizeof(double));
    print_array<double>(my_double,sizeof(my_double)/sizeof(double));

    return 0;
}