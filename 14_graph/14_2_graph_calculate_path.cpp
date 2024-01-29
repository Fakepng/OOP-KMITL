#include <iostream>
#include <vector>
using namespace std;

class Edge;
class Node;

class Edge{
    public :
    int cost;
    Node* node;

    Edge(int _cost,Node* dest){
        cost = _cost;
        node = dest;
    }
};

class Node{
public :
    char data;
    int edge_count;
    Edge* edges[5];

    Node(char item){
        data = item;
        edge_count = 0;
    }

    void add_edge(int cost,Node* n){
        edges[edge_count] = new Edge(cost,n);
        edge_count++;
    }

    void print(){ // method in node
        cout << data << "-> ";
        for(int i=0;i<edge_count;i++){
            cout << "(" << edges[i]->cost <<","<< (edges[i]->node)->data << ")";
        }
        cout << endl;
    }
};

void second_order_visited(Node* n){
    for(int i = 0;i<n->edge_count;i++){ // like print
        Node* node1 = (n->edges[i])->node;
        int cost1 = (n->edges[i])->cost;
        for(int j=0;j<node1->edge_count;j++){
            Node* node2 = (node1->edges[j])->node;
            int cost2 = cost1 + (node1->edges[j])->cost;          
            cout << n->data << "->" << node1->data << "->" << node2->data << " = " << cost2 << endl;
        }
    }
}

void third_order_visited(Node* n){
    for(int i = 0;i<n->edge_count;i++){ // like print
        Node* node1 = (n->edges[i])->node;
        int cost1 = (n->edges[i])->cost;
        for(int j=0;j<node1->edge_count;j++){
            Node* node2 = (node1->edges[j])->node;
            int cost2 = cost1 + (node1->edges[j])->cost;          
            for(int k=0;k< node2->edge_count;k++){
            Node* node3 = (node2->edges[k])->node;
            int cost3 = cost2 + (node2->edges[k])->cost;     
            cout << n->data << "->" << node1->data << "->" << node2->data << "->" << node3->data << " = " << cost3 << endl;
            }
        }
    }
}


int main(){

    Node a('A');
    Node b('B');
    Node c('C');
    Node d('D');
    Node e('E');

    a.add_edge(20,&b);
    a.add_edge(2 ,&e);
    a.add_edge(30,&c);

    b.add_edge(20,&a);
    b.add_edge(7 ,&d);
    b.add_edge(6 ,&e);

    c.add_edge(30,&a);
    c.add_edge(1 ,&e);
    c.add_edge(2 ,&d);

    d.add_edge(2 ,&c);
    d.add_edge(7 ,&b);
    d.add_edge(4 ,&e);
    
    e.add_edge(6 ,&b);
    e.add_edge(2 ,&a);
    e.add_edge(1 ,&c);
    e.add_edge(4 ,&d);

    second_order_visited(&a);
    third_order_visited(&a);

    return 0;
}