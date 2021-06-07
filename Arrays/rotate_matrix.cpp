#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>

// Rotate Image (in O(1) space)
// time: O(N*N)

// going around in cycles and using 1 extra bucket to swap elements
void rotate_cycle(vector<vector<int> >& matrix) {
    int n = matrix.size();
    
    for (int i = 0; i < n/2; ++i){
        for(int j=i; j<n-i-1; j++){
            // swap in anti-clockwise direction
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][n-1-i];        // right to top
            matrix[j][n-1-i] = matrix[n-1-i][n-1-j];// bottom to right
            matrix[n-1-i][n-1-j] = matrix[n-1-j][i];// left to bottom
            matrix[n-1-j][i] = temp;                // top to left
        }
    }
}

// easier version
void rotate_ac(int mat[][1000], int n){
    // Step 1: Reverse rows
    for(int row=0; row<n; row++){
        for(int col=0; col<n/2; col++){
            swap(mat[row][col], mat[row][n-1-col]);
        }
    }

    // Step 2: Transpose matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int mat[1000][1000];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }
    
    rotate_ac(mat, n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
