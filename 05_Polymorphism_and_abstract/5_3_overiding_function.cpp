#include <stdio.h>
#include <iostream>

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

int multiply(int a,int b){
    int c = a * b;
    std::cout << "multiply(int,int) : ";
    return c;
}

float multiply(int a,float b){
    float c = a * b;
    std::cout << "multiply(int,float) : ";
    return c;
}

float multiply(float a,int b){
    float c = a * b;
    std::cout << "multiply(float,int) : ";
    return c;
}

int main(){
/*
    printf("%d\n", multiply_int_int(2,1) );
    printf("%f\n", multiply_int_float(2,2.0) );
    printf("%f\n", multiply_float_int(2.0,3.0) );
    */
    std::cout << multiply(2,4) << std::endl;
    std::cout << multiply(2,5.0F) << std::endl;
    std::cout << multiply(2.0F,6) << std::endl;

    return 0;
}