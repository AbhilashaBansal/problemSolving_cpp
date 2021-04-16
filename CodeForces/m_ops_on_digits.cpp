#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll dp[1000000];
void solve(){
    for(int i=0; i<=9; i++){
        dp[i]=1;
    }
    for(int i=10; i<1000000; i++){
        dp[i] = (dp[i-10+1]%mod + dp[i-10+0]%mod)%mod;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    memset(dp, 0, sizeof dp);
    solve();

    while(t--){
        int n, m;
        cin>>n>>m;

        ll ans=0;
        while(n){
            int digit = n%10;
            n /= 10;
            ans += dp[m+digit]%mod;
            ans %= mod;
        }
        cout<<ans%mod<<endl;
    }
    return 0;
}
