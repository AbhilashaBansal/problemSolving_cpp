// O(nlogn) (logn for modular exponentiation)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod (ll)(1e9+7);

ll power(ll x, ll y){
    ll res = 1;    
    x = x%mod;
    if (x == 0) return 0; 
 
    while (y>0){
        // If y is odd, multiply x with result
        if(y&1)
            res=(res*x)%mod;
 
        // y must be even now
        y = y>>1; 
        x = (x*x)%mod;
    }
    return res;
}

ll fn(string s, int n, int k, int mid){
    ll temp=0;
    if(n%2==1){
        string t = s.substr(0, mid-1);
        reverse(t.begin(), t.end());
        string u = s.substr(0, mid)+t;
        if(u<s) temp=1;
    }

    if(n%2==0){
        string t = s.substr(0, mid);
        reverse(t.begin(), t.end());
        string u = s.substr(0, mid)+t;
        if(u<s) temp=1;
    }

    ll ans=0;
    for(int j=mid-1; j>=0; j--){
        int pos = s[j]-'a';
        ans=0;
        ans += pos*power(k, mid-j-1);
        ans %= mod;
        ans += temp;
        ans %= mod;
        temp = ans; // update w/ current ans
    }
    
    return ans%mod;
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
        int k;
        cin>>k;
        string s; cin>>s;
        // ans=0;
        string cur = "";
        int mid = (n+1)/2;

        ll ans = fn(s, n, k, mid);
        cout<<"Case #"<<cnt++<<": "<<ans<<endl;
    }
    return 0;
}
