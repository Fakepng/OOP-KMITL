#include <iostream>
#include <string>
using namespace std;

template <typename T> class prototype_calculator{

public :

    virtual T add(T x,T y)  = 0;

    virtual T subtract(T x,T y)  = 0;

    virtual T multiply(T x,T y)  = 0;

    virtual T sum(T x1,T x2=0,T x3=0,T x4=0,T x5=0,T x6=0,T x7=0,T x8=0,T x9=0,T x10=0) = 0;

};

template <typename T> class universal_calculator : public prototype_calculator<T>{
public :
    static int operate_count;

    static int get_operator_count(){
        return operate_count;
    }

    T add(T x,T y){
        operate_count++;
        return x + y;
    }

    T subtract(T x,T y){
        operate_count++;
        return x - y;
    }

    T multiply(T x,T y){
        operate_count++;
        return x * y;
    }

    T sum(T x1,T x2=0,T x3=0,T x4=0,T x5=0,T x6=0,T x7=0,T x8=0,T x9=0,T x10=0){
        operate_count++;
        return x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10;
    }
};


template <typename T> int universal_calculator<T>::operate_count = 0;

int main(){

    universal_calculator<int> int_calculator;
    universal_calculator<float> float_calculator;
    universal_calculator<double> double_calculator;
    universal_calculator<char> char_calculator;

    cout << "operated : " << universal_calculator<int>::get_operator_count() << "times" << endl;
    cout << "add : substract : multiply" << endl;
    cout << int_calculator.add(6,9) << " : " << int_calculator.subtract(6,9) << " : " << int_calculator.multiply(6,9) <<  endl;
    cout << float_calculator.add(6.6,9.9) << " : " << float_calculator.subtract(6.6,9.9) << " : " << float_calculator.multiply(6.6,9.9) <<  endl;
    cout << double_calculator.add(6.9,9.6) << " : " << double_calculator.subtract(6.9,9.6) << " : " << double_calculator.multiply(6.9,9.6) <<  endl;
    cout << char_calculator.add('A',1) << " : " << char_calculator.subtract('z',3) << " : " << char_calculator.multiply(7,10) <<  endl;

    cout << "operated int : " << universal_calculator<int>::get_operator_count() << "times" << endl;
    cout << "operated float: " << universal_calculator<float>::get_operator_count() << "times" << endl;
    cout << "operated double: " << universal_calculator<double>::get_operator_count() << "times" << endl;
    cout << "operated char: " << universal_calculator<char>::get_operator_count() << "times" << endl;

    cout << "sum" << endl;
    cout << int_calculator.sum(1,2,3,4,5,6,7,8,9,10) << "," << int_calculator.sum(1,2,3,4,5,6,7,8,9) << "," << int_calculator.sum(1,2,3,4,5,6,7,8) << ",";
    cout << double_calculator.sum(1.0F,2.0F,3.0F,4.0F,5.0F,6.0F,7.0F) << "," << double_calculator.sum(1.0F,2.0F,3.0F,4.0F,5.0F,6.0F) << "," << double_calculator.sum(1.0F,2.0F,3.0F,4.0F,5.0F) << "," << double_calculator.sum(1.0F,2.0F,3.0F,4.0F) << ",";
    cout << char_calculator.sum(10,20,30) << "," << char_calculator.sum(64,2) << "," << char_calculator.sum('F') << endl;

    cout << "operated int : " << universal_calculator<int>::get_operator_count() << "times" << endl;
    cout << "operated float: " << universal_calculator<float>::get_operator_count() << "times" << endl;
    cout << "operated double: " << universal_calculator<double>::get_operator_count() << "times" << endl;
    cout << "operated char: " << universal_calculator<char>::get_operator_count() << "times" << endl;

    /*
    operated : 0times
    add : substract : multiply
    15 : -3 : 54
    16.5 : -3.3 : 65.34
    16.5 : -2.7 : 66.24
    B : w : F
    operated int : 3times
    operated float: 3times
    operated double: 3times
    operated char: 3times
    sum
    55,45,36,28,21,15,10,<,B,F
    operated int : 6times
    operated float: 3times
    operated double: 7times
    operated char: 6times
    */

    return 0;
}