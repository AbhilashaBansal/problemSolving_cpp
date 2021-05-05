#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool check(vector <vector<int>> &v, int i, int j, int n, int val) {
    // bool ans1=true, ans2=true;
    if(i!=0){
        // check for upper cell
        if(abs(v[i-1][j]-val)==1) return false;
    }
    if(j!=0){
        // check for left cell
        if(abs(v[i][j-1]-val)==1) return false;
    }
    return true;
}

bool func(vector <vector<int>> &v, int i, int j, int n, vector<int> &vis){
    if(i==n) return true;

    if(j==n){
        return func(v, i+1, 0, n, vis);
    }

    for(int val=1; val<=n*n; val++){
        if(vis[val-1]==1) continue;
        vis[val-1] = 1;
        v[i][j] = val;
        bool isPos = check(v, i, j, n, val);
        if(isPos && func(v, i, j+1, n, vis)){
            vis[val-1] = 0; // bt
            return true;
        }
        vis[val-1] = 0;
        v[i][j] = 0;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        int n;
        cin>>n;
        vector <vector<int>> v(n, vector<int>(n, 0));
        vector <int> used(n*n, 0);
        
        // fn call
        bool ans = func(v, 0, 0, n, used);
        if(ans) {
            // cout<<"YES\n";
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cout<<v[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        else{
            cout<<"-1\n";
        }
    }
    return 0;
}
