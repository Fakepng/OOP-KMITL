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
    //virtual double avg(double x1,double x2,double x3,double x4,double x5) = 0;
    
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
    // << "avg" << endl;
    //cout << cal.avg(1,2,3,4,5) << "," << cal.avg(1,2,3,4) << "," << cal.avg(1,2,3) << "," << cal.avg(1,2) << "," << cal.avg(1) << endl;

    return 0;
}