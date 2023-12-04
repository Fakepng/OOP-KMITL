#include<iostream>
#include<string>

using namespace std;

class calculator{
    float result = 0;
    //float result {0};

public :

    calculator(){
        //result = 0;
    }
/*
    void sum(float a,float b){
        result = a+b;
    }
    */
    void sum(float a,float b,float c){
        result = a+b+c;
    }

    void sum(float a = 0,float b=1,float c = 2,float d = 3){
        cout << a << "." << b << "." << c<< "."<<d<<endl;
        result = a+b+c+d;
    }

/*
    void sum(float a,float b,float c ,float d){
        //cout << a << "." << b << "." << c<< "."<<d<<endl;
        result = a+b+c+d;
    }  

    void sum(float a,float b,float c ){
        float d = 0;
        result = a+b+c+d;
    }
*/


/*
    void max(float a,float b){
        if(a > b) result = a;
        else result = b;
    }
    void max(float a,float b,float c){
        if(a > b && a > c) result = a;
        else if(b > a && b > c) result = b;
        else result = c;
    }
*/
    void max(float a ,float b,float c=0 ,float d = 0){
        if(a > b && a > c && a > d) result = a;
        else if(b > a && b > c && b > d) result = b;
        else if(c > a && c > b && c > d) result = c;
        else result = d;
    }

    void print(){
        cout << "the result is " << result << endl;
    }

};

using namespace std;
int main(){

    calculator c;

    c.sum();
    c.sum(3,4);
    c.sum(1);
    c.sum(1,2,3);

    cout << endl;




    c.max(11,12,13,14);
    c.print();
    c.max(11,12,13);
    c.print();
    c.max(11,12);
    c.print();
    return 0;
}