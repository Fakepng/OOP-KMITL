#include <iostream>
using namespace std;

class Queue{

    int *items;
    int head_idx,tail_idx;
    int capacity;

public :
    Queue(int _capacity){
        capacity = _capacity;
        head_idx = 0;
        tail_idx = -1;
        items = new int[capacity];
    }

    void enqueue(int n){
        tail_idx++;
        items[tail_idx] = n;     
    }

    int dequeue(){
        int return_item = items[head_idx];
        head_idx++;
        return return_item;
    }
/*
    bool is_empty(){
        if(tail_idx > head_idx) return true;  
        return false;
    }
*/
    bool is_empty(){
        return tail_idx > head_idx;
    }


    bool is_full(){
        if((tail_idx) >= capacity) return true;
        return false;
    }

    bool is_full(){
        return (tail_idx) >= capacity;
    }

    ~Queue(){
        delete items;
    }
};

int main(){
    
    Queue q(10);
    q.enqueue(1); q.enqueue(10); q.enqueue(100);
    cout << q.dequeue() << endl;
    q.enqueue(2); q.enqueue(20); q.enqueue(200);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
/*
    Queue q2(12);
    q.enqueue(2); 
    q.enqueue(4); 
    q.enqueue(6);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(8); 
    q.enqueue(10); 
    q.enqueue(12);
    cout << q.dequeue() << endl; 

    Queue q3(12);
    q.enqueue(1); 
    q.enqueue(1); 
    q.enqueue(1);
    q.enqueue(2); 
    q.enqueue(2); 
    q.enqueue(2);
    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl; 
    q.enqueue(3);
    cout << q.dequeue() << endl; 
*/


    

    return 0;
}