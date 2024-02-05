#include <iostream>
using namespace std;

class Stack{

    int *items;
    int top_idx;
    int capacity;

public :
    Stack(int _capacity){
        capacity = _capacity;
        top_idx = -1;
        items = new int[capacity];
    }

    void push(int n){
        top_idx++;
        items[top_idx] = n;
    }

    int pop(){
        int return_item = items[top_idx];
        top_idx--;
        return return_item;
    }
/*
    bool is_empty(){
        if(top_idx < 0) return true;
        return false;
    }
*/
    bool is_empty(){
        return top_idx < 0;
    }
/*
    bool is_full(){
        if((top_idx + 1) >= capacity) return true;
        return false;
    }
*/
    bool is_full(){
        return (top_idx + 1) >= capacity;
    }

    ~Stack(){
        delete items;
    }
};

int main(){

    // Stack s(6);
    // s.push(9); s.push(8); s.push(7);
    // cout << s.pop();
    // s.push(4); s.push(5); s.push(6);
    // cout << s.pop();
    // cout << s.pop();
    // cout << s.pop();
    // cout << s.pop();
    // cout << s.pop();

    // Stack s2(6);
    // s2.push(1);
    // s2.push(10);
    // s2.push(100);
    // cout << s2.pop() << endl;
    // s2.push(2);
    // s2.push(20);
    // s2.push(200);
    // cout << s2.pop() << endl;
    // cout << s2.pop() << endl;
    // cout << s2.pop() << endl;
    // cout << s2.pop() << endl;

    // Stack s3(6);
    // s3.push(1);
    // cout << s3.pop() << endl;
    // s3.push(2);
    // s3.push(3);
    // cout << s3.pop() << endl;
    // cout << s3.pop() << endl;
    // s3.push(2);
    // s3.push(20);
    // s3.push(200);
    // cout << s3.pop() << endl;
    // cout << s3.pop() << endl;
    // cout << s3.pop() << endl;

    return 0;
}