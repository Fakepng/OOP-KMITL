#include <iostream>
#include <vector>
using namespace std;

class sub_problem{
public :
    int limit_number;
    int x,y;
    
    sub_problem(int limit,int _x,int _y){
        limit_number = limit;
        x = _x;
        y = _y;
    }

    //virtual bool check(int** table) = 0; // check complete table
    //virtual bool check_valid(int** table) = 0; // check valid table
};

class square_problem : public sub_problem{
public :
    int square_size;

    square_problem(int limit,int _x,int _y,int size) : sub_problem(limit,_x,_y){
        square_size = size;
    }

    bool check(int** table){
        bool check_flag[limit_number] = {0};

        for(int i=0;i<square_size;i++){
            for(int j=0;j<square_size;j++){
                if(table[y + i][x + j] != 0){
                    check_flag[table[y + i][x + j] - 1] = true;
                }
            }
        }

        bool ans = true;
        for(int i=0;i<limit_number;i++){
            ans = ans && check_flag[i];
        }
        return ans;
    }

    bool check_valid(int** table){
        bool check_flag[limit_number] = {0};

        for(int i=0;i<square_size;i++){
            for(int j=0;j<square_size;j++){
                if(table[y + i][x + j] != 0){
                    if(check_flag[table[y + i][x + j] - 1] != true){
                        check_flag[table[y + i][x + j] - 1] = true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

class row_problem : public sub_problem{
public :
    row_problem(int limit,int _x,int _y) : sub_problem(limit,_x,_y){
    }

    bool check(int** table){
        bool check_flag[limit_number] = {0};

        for(int i=0;i<limit_number;i++){
            if(table[y][x + i] != 0){
                check_flag[table[y][x + i] - 1] = true;
            }
        }

        bool ans = true;
        for(int i=0;i<limit_number;i++){
            ans = ans && check_flag[i];
        }
        return ans;
    }

    bool check_valid(int** table){
        bool check_flag[limit_number] = {0};

        for(int i=0;i<limit_number;i++){
            if(table[y][x + i] != 0){
                if(check_flag[table[y][x + i] - 1] != true){
                    check_flag[table[y][x + i] - 1] = true;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};

class column_problem : public sub_problem{
public :
    column_problem(int limit,int _x,int _y) : sub_problem(limit,_x,_y){
    }

    bool check(int** table){
        bool check_flag[limit_number] = {0};

        for(int i=0;i<limit_number;i++){
            if(table[y + i][x] != 0){
                check_flag[table[y + i][x] - 1] = true;
            }
        }

        bool ans = true;
        for(int i=0;i<limit_number;i++){
            ans = ans && check_flag[i];
        }
        return ans;
    }

    bool check_valid(int** table){
        bool check_flag[limit_number] = {0};

        for(int i=0;i<limit_number;i++){
            if(table[y + i][x] != 0){
                if(check_flag[table[y + i][x] - 1] != true){
                    check_flag[table[y + i][x] - 1] = true;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};

class soduku_checker{
public :
    int** table;
    sub_problem* problems[27];

    soduku_checker(int **t){
        table = t;

        for(int i=0;i<9;i++){
            problems[i] = new square_problem(9,(i%3) * 3,(i/3) * 3,3);
            problems[9+i] = new row_problem(9,0,i);
            problems[18+i] = new column_problem(9,i,0);
            problems[0] = 88.88;
            problems[1] = new sub_problem();
        }
    }

    bool check(){
        bool ans = true;
        for(int i=0;i<27;i++){
            ans = ans && (problems[i]->check(table));
        }
        return ans;
    }

    bool check_valid(){
        bool ans = true;
        for(int i=0;i<27;i++){
            ans = ans && (problems[i]->check_valid(table));
        }
        return ans;
    }

    void print(){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << table[i][j] << " ";
            }
        cout << endl;
        }
    }

    vector<vector<int>> slot;
    int max_slot;
    int complete_fill;

    bool solve(){

        complete_fill = 0;
        slot.clear();
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(table[i][j] == 0){
                    vector<int> tmp_slot;
                    tmp_slot.push_back(i);
                    tmp_slot.push_back(j);
                    slot.push_back(tmp_slot);
                }
            }
        }
            
        max_slot = slot.size();
            
        solver(0);
        return complete_fill;
    }

private :
    void solver(int n){

        if(n == max_slot){
            complete_fill = 1;
        }
        else{
            for(int i=0;i<9;i++){
                table[slot[n][0]][slot[n][1]] = i+1;
                if(check_valid() == true){
                    solver(n+1);
                }
                if(complete_fill == 1){
                    return;
                }
            }
            if(complete_fill == 1){
                return;
            }
            table[slot[n][0]][slot[n][1]] = 0;
        }
    }

};

int main(){

    int **ex1;
    ex1 = new int *[9];
    ex1[0] = new int[9] {5,3,0,0,7,0,0,0,0};
    ex1[1] = new int[9] {6,0,0,1,9,5,0,0,0};
    ex1[2] = new int[9] {0,9,8,0,0,0,0,6,0};
    ex1[3] = new int[9] {8,0,0,0,6,0,0,0,3};
    ex1[4] = new int[9] {4,0,0,8,0,3,0,0,1};
    ex1[5] = new int[9] {7,0,0,0,2,0,0,0,6};
    ex1[6] = new int[9] {0,6,0,0,0,0,2,8,0};
    ex1[7] = new int[9] {0,0,0,4,1,9,0,0,5};
    ex1[8] = new int[9] {0,0,0,0,8,0,0,7,9};    

    int **ex2;
    ex2 = new int *[9];
    ex2[0] = new int[9] {5,3,4,6,7,8,9,1,2};
    ex2[1] = new int[9] {6,7,2,1,9,5,3,4,8};
    ex2[2] = new int[9] {1,9,8,3,4,2,5,6,7};
    ex2[3] = new int[9] {8,5,9,7,6,1,4,2,3};
    ex2[4] = new int[9] {4,2,6,8,5,3,7,9,1};
    ex2[5] = new int[9] {7,1,3,9,2,4,8,5,6};
    ex2[6] = new int[9] {9,6,1,5,3,7,2,8,4};
    ex2[7] = new int[9] {2,8,7,4,1,9,6,3,5};
    ex2[8] = new int[9] {3,4,5,2,8,6,1,7,9};                   

    soduku_checker s1(ex1);
    s1.print();
    cout << s1.check() << "," << s1.check_valid() << endl;
    s1.solve();
    s1.print();

/*
    soduku_checker s2(ex2);
    cout << s2.check() << endl;
*/

    sub_problem p,o;0
    square_problem i;
    row_problem j;

    p = i;
    i = p;
    j = 55;
    p = o;




    return 0;
}