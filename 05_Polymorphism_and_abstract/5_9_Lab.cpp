#include <iostream>
#include <string>
using namespace std;

class prototype_calculator{
public :
    virtual double add(double x,double y)  = 0;
    virtual double subtract(double x,double y)  = 0;
    virtual double multiply(double x,double y)  = 0;

    virtual double sum(double x1,double x2,double x3,double x4,double x5,double x6,double x7,double x8,double x9,double x10) = 0;

    // special point
    virtual double avg(double x1,double x2,double x3,double x4,double x5) = 0;

};

class double_calculator : public prototype_calculator{
public :
    double add(double x,double y){
        return x + y;
    }

    double subtract(double x,double y){
        return x - y;
    }

    double multiply(double x,double y){
        return x * y;
    }

    double sum(double x1 = 0,double x2 = 0,double x3 = 0,double x4 = 0,double x5 = 0,double x6 = 0,double x7 = 0,double x8 = 0,double x9 = 0,double x10 = 0){
        return x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10;
    }

    // special points
    double avg(double x1,double x2,double x3,double x4,double x5){
       return (x1 + x2 + x3 + x4 + x5) / 5;
    }

    double avg(double x1,double x2,double x3,double x4){
        return (x1 + x2 + x3 + x4) / 4;
    }

    double avg(double x1,double x2,double x3){
        return (x1 + x2 + x3) / 3;
    }

    double avg(double x1,double x2){
        return (x1 + x2) / 2;
    }

    double avg(double x1){
        return x1;
    }

};

int main(){

    double_calculator cal;
    cout << "add : substract : multiply" << endl;
    cout << cal.add(6,9) << " : " << cal.subtract(6,9) << " : " << cal.multiply(6,9) <<  endl;
    cout << "sum" << endl;
    cout << cal.sum(1,2,3,4,5,6,7,8,9,10) << "," << cal.sum(1,2,3,4,5,6,7,8,9) << "," << cal.sum(1,2,3,4,5,6,7,8) << ",";
    cout << cal.sum(1,2,3,4,5,6,7) << "," << cal.sum(1,2,3,4,5,6) << "," << cal.sum(1,2,3,4,5) << "," << cal.sum(1,2,3,4) << ",";
    cout << cal.sum(1,2,3) << "," << cal.sum(1,2) << "," << cal.sum(1) << endl;

    // special point
    cout << "avg" << endl;
    cout << cal.avg(1,2,3,4,5) << "," << cal.avg(1,2,3,4) << "," << cal.avg(1,2,3) << "," << cal.avg(1,2) << "," << cal.avg(1) << endl;

    return 0;
}