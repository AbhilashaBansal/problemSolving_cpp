#include <bits/stdc++.h>
using namespace std;

int botUp(int *ht, int n, int k){
    int *dp = new int[n+1];
    dp[1] = 0;
    for(int i=2; i<=n; i++){
        int ans=INT_MAX;
        for(int j=1; j<=k; j++){
            if(i-j<1) break;
            ans = min(ans, dp[i-j] + abs(ht[i-1] - ht[i-j-1]) );
        }
        dp[i] = ans;
    }
    return dp[n];
}

int topDown(int ht[], int i, int n, int k, int dp[]){
    if(i==n-1) return dp[i]=0;

    if(dp[i]!=-1) return dp[i];

    int ans=INT_MAX;
    for(int j=1; j<=k; j++){
        if(i+j>n-1) break;
        ans = min(ans, topDown(ht, i+j, n, k, dp) + abs(ht[i]-ht[i+j]) );
    }
    return dp[i]=ans;
}

int main() {
    int n, k;
    cin>>n>>k;
    int *ht = new int[n];
    for(int i=0; i<n; i++){
        cin>>ht[i];
    }
    // cout<<botUp(ht,n,k)<<endl;

    int *dp = new int[n];
    for(int i=0; i<n; i++) 
        dp[i] = -1;
    cout<<topDown(ht, 0, n, k, dp);
    return 0;
}
