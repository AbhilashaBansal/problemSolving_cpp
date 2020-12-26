#include <bits/stdc++.h>
using namespace std;

int cost(vector<int> B) {
    int n = B.size();
    int **dp = new int* [n];
    for(int i=0; i<n; i++){
        dp[i] = new int[2];
        dp[i][0] = dp[i][1] = 0;
    }
    
    dp[0][0] = dp[0][1] = 0;
    for(int i=1; i<n; i++){
        //0 -> ai=1
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + abs(1-B[i-1]));
        
        //1 -> ai=bi
        dp[i][1] = max(dp[i-1][0]+abs(1-B[i]), dp[i-1][1] + abs(B[i]-B[i-1]));
    }
    return max(dp[n-1][0], dp[n-1][1]);
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector <int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        cout<<cost(v);
    }
    return 0;
}
