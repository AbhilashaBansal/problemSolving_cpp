// RECURSION + NUMBER THEORY

// O (nlogn + n^2) = O (n^2)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const ll mod = 1000000007;
const int siz = 1005;
ll fact[siz] = {0};
ll invFact[siz] = {0};

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

void Combination(){
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < siz; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invFact[i] = fast_pow(fact[i], mod - 2);
    }
}

// O(n^2)
ll func(vector <int> v){
    // root is fixed
    if(v.size()<=1) return 1;

    vector <int> small, large;
    for(int i=1; i<v.size(); i++){
        if(v[i]<=v[0]) small.push_back(v[i]); // O(n)
        else large.push_back(v[i]);
    }
    int n=small.size(), m=large.size();

    ll temp = (func(small)%mod *func(large)%mod ) %mod;
    temp *= (C(n+m, m)%mod);
    return temp%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Combination(); // nlogn
    int t;
    t=1;
    int cnt=1;
    while(t--){
        int n;
        cin>>n;

        vector <int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];

        ll ways = func(v);
        cout<<ways-1<<endl;
    }
    return 0;
}
