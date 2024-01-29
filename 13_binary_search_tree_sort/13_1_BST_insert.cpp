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


class BST{
public:
    Node *root = nullptr;

    void insert(char item){
        if(root == nullptr){
            root = new Node(item);
        }
        else{
            Node* p = root;
            while(true){
                if(item < p->data){ // go left
                    if(p->left == nullptr){ 
                        p->left = new Node(item);
                        break;
                    }
                    else p = p->left;
                }
                else{
                    if(p->right == nullptr){
                        p->right = new Node(item);
                        break;
                    }
                    else p = p->right;                   
                }
            }
        }
    }

    bool search(char item){
        Node *p = root;
        while(p != nullptr){
            if(item == p->data){
                return true;
            }
            else if(item < p->data){
                p=p->left;
            }
            else{
                p=p->right;
            }
        }
        return false;
    }

    void print_tree(){
        int depth = find_depth(0,root) + 1;
        int width = pow2(depth);
        vector<vector<char>> table;
        for(int i=0;i<depth*2;i++){
            table.push_back(vector<char>());
            for(int j=0;j<width + 1;j++){
                table[i].push_back(' ');
            }
        }

        print_vector(&table,0,width/2,width/4,root);

        for(int i=0;i<(depth - 1) * 2;i++){
            for(int j=0;j<width;j++){
                cout << table[i][j];
            }
            cout << endl;
        }
    }

    void print_preorder(){      preorder(root); }
    void print_inorder(){       inorder(root);  }
    void print_postorder(){     postorder(root); }

private:
    void preorder(Node* p){
        if(p == nullptr) return;

        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }

    void inorder(Node* p){
        if(p == nullptr) return;
        
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }

    void postorder(Node* p){
        if(p == nullptr) return;
    
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }

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


};

int main(){

    BST tree;
    tree.insert('G');
    tree.insert('D');
    tree.insert('J');
    tree.insert('B');
    tree.insert('E');
    tree.insert('A');
    tree.insert('C');
    tree.insert('F');
    tree.insert('H');
    tree.insert('I');
    cout << endl;
    tree.print_tree();

    cout << tree.search('C') << endl;
    cout << tree.search('X') << endl;
    cout << tree.search('K') << endl;
    cout << tree.search('H') << endl;

    BST tree2;
    tree2.insert('E');
    tree2.insert('F');
    tree2.insert('G');
    tree2.insert('H');
    tree2.insert('I');
    tree2.insert('J');
    cout << endl;
    tree2.print_tree();

    tree.print_inorder();
    cout << endl;
    tree2.print_inorder();
    cout << endl;

    return 0;
}