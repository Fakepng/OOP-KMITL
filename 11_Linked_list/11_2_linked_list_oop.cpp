#include <iostream>
using namespace std;

class Node{
public :
    char data;
    Node* next;

    Node(char item){
        data = item;
        next = nullptr;
    }
};

class Linked_list{
    Node* head;

public :
    Linked_list(){
        head = nullptr;
    }

    void push_back(char item){ // insert to last node
        Node* new_node = new Node(item);
    
        if(head == nullptr){ // for empty head list
            head = new_node;
        }
        else{
            Node* p = head;
            while(p->next != nullptr){
                p = p->next;
            }
            p->next = new_node;
        }
    }

    void push_front(char item){ // insert to first of list
        Node* new_node = new Node(item);
        if(head == nullptr){ // for empty head list
            head = new_node;
        }
        else{
            new_node->next = head; // step 1
            head = new_node; // step 2
        }
    }

    void remove_at(int index){ // insert to first of list
        Node *p = head;
        for(int i=0;i<index-1;i++){ // traverse to index - 1
            p = p->next;
        }

        Node *old_node = p->next;
        p->next = (p->next)->next; // step 2
        delete old_node;
    }

/*
    void remove_at(int index){ // insert to first of list
        Node *p = head;
        for(int i=0;i<index-1;i++){ // traverse to index - 1
            p = p->next;
        }

        p->next = (p->next)->next; // step 2
    }
*/

    void insert_after(char item,int index){
        Node *p = head;
        for(int i=0;i<index;i++){ // traverse to index
            p = p->next;
        }
        Node *new_node = new Node(item);
        new_node->next = p->next; // step 2 point to next

        p->next = new_node; // step 3 point to new node
    }

    void print(){
        Node* p = head;
        while(p!=nullptr){
            cout << p->data << "->";
            p=p->next;
        }
        cout << "null" << endl;
    }



};

int main(){

    Linked_list l1;
    l1.push_back('A');
    l1.push_back('B');
    l1.push_back('C');
    l1.print();
    l1.push_front('F');
    l1.push_front('G');
    l1.print();
    l1.remove_at(2);
    l1.print();
    l1.insert_after('K',1);
    l1.print();

    return 0;
}