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

    Stack s(6);
    s.push(9); s.push(8); s.push(7);
    cout << s.pop();
    s.push(4); s.push(5); s.push(6);
    cout << s.pop();
    cout << s.pop();
    cout << s.pop();
    cout << s.pop();
    cout << s.pop();
/*
    Stack s2(6);
    s.push(1); 
    s.push(10); 
    s.push(100);
    cout << s.pop() << endl;
    s.push(2); 
    s.push(20); 
    s.push(200);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    Stack s3(6);
    s.push(1); 
    cout << s.pop();
    s.push(2); s.push(3);
    cout << s.pop();
    cout << s.pop();
    s.push(4); s.push(5); s.push(6);
    cout << s.pop();
    cout << s.pop();
    cout << s.pop();
    cout << s.pop();
*/
    return 0;
}