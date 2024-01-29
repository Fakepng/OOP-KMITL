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

void print_preorder(Node* p){
    if(p == nullptr) return;

    cout << p->data << " ";
    print_preorder(p->left);
    print_preorder(p->right);
}

void print_inorder(Node* p){
    if(p == nullptr) return;
    
    print_inorder(p->left);
    cout << p->data << " ";
    print_inorder(p->right);
}

void print_postorder(Node* p){
    if(p == nullptr) return;
  
    print_postorder(p->left);
    print_postorder(p->right);
    cout << p->data << " ";
}

int main(){

    Node *root = new Node('H');
    root->left  = new Node('A');
    root->right = new Node('I');
    (root->left) ->left  = new Node('R');
    (root->left) ->right = new Node('U');
    (root->right)->left  = new Node('5');
    ((root->left)->right)->left = new Node('H');
    ((root->right)->left)->right = new Node('5');

    cout << endl;
    print_tree(root);
    print_preorder(root); cout<< endl;
    print_inorder(root); cout<< endl;
    print_postorder(root); cout<< endl;


/*
    Node *root = new Node('n');
    root->left  = new Node('A');
    root->right = new Node('a');
    (root->left) ->left  = new Node('t');
    (root->left) ->right = new Node('k');
    (root->right)->left  = new Node('i');
    ((root->left)->right)->left = new Node('c');
    ((root->right)->left)->right = new Node('t');
    ((root->left)->left)->left = new Node('A');
    ((root->left)->left)->right = new Node('t');
    ((root->left)->right)->right = new Node('O');
    ((root->right)->left)->left = new Node('T');
    ((root->right)->right) = new Node('4');
    ((root->right)->right)->left = new Node('n');
    ((root->right)->right)->right = new Node('4');

    cout << endl;
    print_tree(root);
    print_preorder(root); cout<< endl;
    print_inorder(root); cout<< endl;
    print_postorder(root); cout<< endl;
*/
/*


    Node *root = new Node('H');
    root->right = new Node('i');
    ((root->right)->right) = new Node('g');
    ((root->right)->right)->right = new Node('h');
    (((root->right)->right)->right)->right = new Node('5');

    cout << endl;
    print_tree(root);
    print_preorder(root); cout<< endl;
    print_inorder(root); cout<< endl;
    print_postorder(root); cout<< endl;

*/

    return 0;
}