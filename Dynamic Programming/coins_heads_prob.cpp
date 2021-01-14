#include <bits/stdc++.h>
using namespace std;
#define ll long long int

double a[3005];
double dp[3005][3005];

double solve(ll n, ll h){
    if(h==0) return 1;
    if(n==0) return 0;

    if(dp[n][h]>-1.0) return dp[n][h];

    dp[n][h] = a[n-1]*solve(n-1, h-1) + (1-a[n-1])*solve(n-1, h);
    return dp[n][h];
}

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    ll heads = (n+1)/2;
    
    memset(dp, -1.0, sizeof dp);
    cout<<setprecision(10)<<solve(n, heads)<<endl;
    return 0;
}
  
