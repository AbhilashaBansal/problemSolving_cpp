#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>

// Spiral Print of a Matrix
// O(N*M)

vector<int> spiralPrint (vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    
    int sr=0, sc=0, er=n-1, ec=m-1;
    vector<int> ans;
    while(sr<=er && sc<=ec){
        for(int i=sc; i<=ec; i++){
            ans.push_back(matrix[sr][i]);
        }
        sr++;
        for(int i=sr; i<=er; i++){
            ans.push_back(matrix[i][ec]);
        }
        ec--;
        
        if(sr<=er){
            for(int i=ec; i>=sc; i--){
                ans.push_back(matrix[er][i]);
            }
            er--;
        }
        if(sc<=ec){
            for(int i=er; i>=sr; i--){
                ans.push_back(matrix[i][sc]);
            }
            sc++;
        }
    }
    
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    vector<int> ans = spiralPrint(v);
    for(int x: ans) cout<<x<<" ";

    return 0;
}
