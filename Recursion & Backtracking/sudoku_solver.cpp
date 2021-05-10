// Recursion + Backtracking to solve Sudoku
// O(9^(81)) -> however lots of non feasible options would be eliminated after check itself, 
// and quite some cells would already be filled, hence running time would be less than this

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool check(int i, int j, int no, int mat[][9]){
    for(int col=0; col<9; col++){
        if(mat[i][col]==no && col!=j) return false;
    }
    for(int row=0; row<9; row++){
        if(mat[row][j]==no && row!=i) return false;
    }
    int sr = (i/3)*3;
    int sc = (j/3)*3;
    for(int x=sr; x<sr+3; x++){
        for(int y=sc; y<sc+3; y++){
            if(mat[x][y]==no) return false;
        }
    }
    return true;
}

bool utils(int i, int j, int mat[][9]){
    if(i==9) return true;
    if(j==9) return utils(i+1, 0, mat);
    
    if(mat[i][j]!=0) return utils(i, j+1, mat);
    
    for(int no=1; no<=9; no++){
        bool pos = check(i, j, no, mat);
        mat[i][j] = no;
        if(pos && utils(i, j+1, mat)) return true;
        // else backtrack
        mat[i][j] = 0;
    }
    return false;
}

bool isItSudoku(int matrix[9][9]) {
    //Complete this function
	bool ans = utils(0, 0, matrix);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mat[9][9] = {
        2, 7, 0, 0, 0, 0, 9, 0, 0,
        0, 9, 4, 2, 0, 5, 0, 0, 0,
        0, 0, 0, 4, 9, 0, 2, 8, 0,
        9, 0, 2, 0, 6, 3, 1, 0, 0,
        0, 3, 0, 9, 0, 8, 0, 7, 0,
        0, 0, 0, 5, 0, 0, 3, 0, 0,
        0, 0, 7, 0, 0, 0, 0, 3, 1,
        4, 8, 9, 3, 7, 1, 0, 0, 0,
        0, 0, 3, 0, 0, 0, 0, 0, 0
    };
    bool isPos = isItSudoku(mat);
    if(!isPos) cout<<"No Solution\n";
    else{
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
