#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Optimal Game Strategy
// O(N^2)

ll dp[1000][1000];

ll solve(vector<int> values, int i, int j){
    if(i>j) 
        return dp[i][j]=0;
    if(dp[i][j]!=-1) 
        return dp[i][j]; 
    if(i==j) 
        return dp[i][j]=values[i];
    
    if(i+1==j){
        return dp[i][j]=(values[i]>=values[j]?values[i]:values[j]);
    }
    
    ll op1_a = values[i] + solve(values, i+2, j);
    ll op1_b = values[i] + solve(values, i+1, j-1);
    // opponent would minimize next points for us, no matter what we pick
    ll op1 = min(op1_a, op1_b);
    ll op2_a = values[j] + solve(values, i+1, j-1);
    ll op2_b = values[j] + solve(values, i, j-2);
    // opponent would minimize next points for us, no matter what we pick
    ll op2 = min(op2_a, op2_b);
    
    // we can maximize from the 2 choices available to us
    return dp[i][j]=max(op1, op2);
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
        vector <int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
       
        memset(dp, -1, sizeof dp);
        cout<<solve(v, 0, n-1)<<endl;
    }
    return 0;
}
