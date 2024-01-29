#include <iostream>
using namespace std;

class Node{
public :
    char data;
    Node* next;
};

void add_node(Node** h,char item){
    if(*h == nullptr){ // for empty head list
        (*h) = new Node();
        (*h)->data = item;
        (*h)->next = nullptr;
    }
    else{
        Node* p = *h;
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = new Node();
        (p->next)->data = item;
        (p->next)->next = nullptr; 
    }
}

int main(){


    char arr[10];
    Node* head = nullptr;
    
    head = new Node();
    head->data = 'A';
    head->next = nullptr;

    (head->next) = new Node();
    (head->next)->data = 'B';
    (head->next)->next = nullptr;

    (head->next)->next = new Node();
    ((head->next)->next)->data = 'C';
    ((head->next)->next)->next = nullptr;

    cout << head->data << endl;
    cout << (head->next)->data << endl;
    cout << ((head->next)->next)->data << endl;

    Node* head2 = nullptr;
    add_node(&head2,'A');
    add_node(&head2,'B');
    add_node(&head2,'C');
    add_node(&head2,'D');

    cout << endl;
    cout << head2->data << endl;
    cout << (head2->next)->data << endl;
    cout << ((head2->next)->next)->data << endl;
    cout << (((head2->next)->next)->next)->data << endl;

    return 0;
}