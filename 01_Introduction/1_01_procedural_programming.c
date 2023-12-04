#include<stdio.h>

int multiply_int_int(int a,int b){
    int c = a * b;
    return c;
}

float multiply_int_float(int a,float b){
    float c = a * b;
    return c;
}

float multiply_float_int(float a,int b){
    float c = a * b;
    return c;
}

int main(){

    int a,b;
    float c,d;
    a = 1;
    b = 2;
    c = 3;
    d = 4;

    printf("%d\n", multiply_int_int(    a,b)); // 2
    printf("%f\n", multiply_int_float(  a,c)); // 3.00
    printf("%d\n", multiply_float_int(  d,b)); // what happened! 0

    return 0;
}