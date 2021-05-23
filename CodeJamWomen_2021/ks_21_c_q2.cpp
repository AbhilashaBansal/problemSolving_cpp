// O(sqrt(N))
// represent a number as sum of 1 or more consecutive natural numbers

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll fn(ll g) {
    ll G = 2*g;
    ll ans=0;
    for (ll i=1; i<=sqrt(G); i++){
        if (G%i == 0){
            ll a = i;
            ll b = G/i;
            // cout<<a<<" "<<b<<endl;
            if((a+b-1)%2 || (b-a-1)%2){
                continue;
            }
            ll n = (a+b)/2;
            ll m = (b-a)/2;
            ans++;
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        ll n;
        cin>>n;
        ll ans = fn(n);
        cout<<"Case #"<<cnt++<<": "<<ans<<endl;
    }
    return 0;
}
