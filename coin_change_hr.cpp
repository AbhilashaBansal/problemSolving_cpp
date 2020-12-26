#include <bits/stdc++.h>
using namespace std;

long long dp[355];
long long helper(vector <int> v, int money){

    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    for(int i=0; i<v.size(); i++){
        //i th coin can contribute to any change value greater than itself
        for(int mon=v[i]; mon<=money; mon++) {
            dp[mon] += dp[mon-v[i]];
        }
    }
    return dp[money];
}

int main() {
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int money;
    cin>>money;
    cout<<helper(v, money);
    return 0;
}
