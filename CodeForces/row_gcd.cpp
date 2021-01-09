#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int n, m;
    cin>>n>>m;
    ll* a = new ll[n];
    ll* b = new ll[m];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
    }

    ll g = 0;
    for(int i=1; i<n; i++){
        g = __gcd(g, abs(a[i]-a[0]));
    }

    for(int i=0; i<m; i++){
        cout<<__gcd(a[0]+b[i], g)<<" ";
    }
    
    return 0;
}
