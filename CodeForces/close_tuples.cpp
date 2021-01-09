#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 300500;
const int mod = 1000000007;
ll fact[N];
ll invFact[N];

ll fast_pow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = (a * a) % mod;
            p /= 2;
        } else {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}

ll C(int n, int k) {
    if (k > n) {
        return 0;
    }
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}

int main() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invFact[i] = fast_pow(fact[i], mod - 2);
    }
    int t;
    cin>>t;
    while(t--){
        ll n, m, k;
        cin>>n>>m>>k;

        ll *a = new ll[n];
        for(ll i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a, a+n);
        // for(ll i=0; i<n; i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;

        ll i=0;
        ll ans=0;
        
        while(i<=n-m){
            ll no=a[i];
            ll idx = upper_bound(a+i, a+n, no+k) - a;
            idx--;
            ll options = idx-i;
            if(options>=m-1){
                ans = (ans + C(options, m-1))%mod;
                ans %= mod;
            }
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

