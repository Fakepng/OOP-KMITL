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

void print_node(Node n){

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

    //a.print();
    //b.print();
    //c.print();
    //d.print();
    //e.print();

    cout << ((a.edges[1]->node)->edges[0]->node)->data;

    //cout << a.edges[0]->cost + b.edges[1]->cost + d.edges[2]->cost << endl; // 31
    //cout << a.edges[0]->cost + b.edges[2]->cost << endl; // 26
    //cout << a.edges[1]->cost << endl; // 2

    return 0;
}