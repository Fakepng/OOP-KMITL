#include <iostream>
#include <vector>
using namespace std;

/*
class Node{
    char data;
    Node* path1;
    Node* path2;
    Node* path3;
    Node* ...
};
*/

class Node{
public :
    char data;
    Node* left;
    Node* right;

    Node(char item){
        data = item;
        left = nullptr;
        right = nullptr;
    }
};

int max(int a,int b){
    if(a > b) return a;
    return b;
}

int find_depth(int n,Node* p){
    if(p == nullptr) return n;
    return max(find_depth(n+1,p->left) , find_depth(n+1,p->right));
}

int pow2(int n){
    int result = 1;
    for(int i=0;i<n;i++){
        result *= 2;
    }
    return result;
}

void print_vector(vector<vector<char>> *v,int level,int loc,int space,Node* p){

    if( p == nullptr) return;
    (*v)[level][loc] = p->data;

    if(p->left != nullptr){
        for(int i=0;i<space - 2;i++){
            (*v)[level][loc - i - 1] = '_';
        }
        (*v)[level+1][loc - space + 1] = '/';
        print_vector(v,level+2,loc - space,space/2,p->left);
    }

    if(p->right != nullptr){
        for(int i=0;i<space - 2;i++){
            (*v)[level][loc + i + 1] = '_';
        }
        (*v)[level+1][loc + space - 1] = '\\';
        print_vector(v,level+2,loc + space,space/2,p->right);
    }
}

void print_tree(Node* head){
    int depth = find_depth(0,head) + 1;
    int width = pow2(depth);
    vector<vector<char>> table;
    for(int i=0;i<depth*2;i++){
        table.push_back(vector<char>());
        for(int j=0;j<width + 1;j++){
            table[i].push_back(' ');
        }
    }

    print_vector(&table,0,width/2,width/4,head);

    for(int i=0;i<(depth - 1) * 2;i++){
        for(int j=0;j<width;j++){
            cout << table[i][j];
        }
        cout << endl;
    }

}

int main(){

    Node *root = new Node('A');

    root->left  = new Node('B');
    root->right = new Node('H');

    (root->left) ->left  = new Node('C');
    (root->left) ->right = new Node('D');
    (root->right)->left  = new Node('G');

    ((root->left)->right)->left = new Node('E');
    ((root->right)->left)->right = new Node('F');

    cout << endl;
    print_tree(root);

    ((root->left)->left)->left = new Node('l');
    ((root->left)->left)->right = new Node('M');
    ((root->left)->right)->right = new Node('M');
    ((root->right)->left)->left = new Node('O');

    cout << endl;
    print_tree(root);

    ((root->right)->right) = new Node('I');
    ((root->right)->right)->left = new Node('J');
    ((root->right)->right)->right = new Node('K');

    cout << endl;
    print_tree(root);

    cout << root->data << endl;
    cout << (root->left)->data << endl;
    cout << ((root->left)->left)->data << endl;
    cout << (((root->left)->left)->left)->data << endl;
    cout << (((root->left)->left)->right)->data << endl;

    root->right = nullptr;
    print_tree(root);

    ((root->left)->left)->left = nullptr;
    print_tree(root);
    (root->left)->right = nullptr;
    print_tree(root);

    return 0;
}