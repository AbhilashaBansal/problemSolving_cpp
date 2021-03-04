#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// given: a square board of size nxn,
// target: color exactly u, r, d, l boxes in uppermost row, right most column, bottom most row & left most column respectively

bool check(int n, int u, int r, int d, int l){
    if(u>n || r>n || d>n || l>n) return false;
    if(u==n || d==n){
        if(l==0 || r==0) return false;
    }
    if(l==n || r==n){
        if(u==0 || d==0) return false;
    }

    if(u==n && d==n){
        if(l<2 || r<2) return false;
    }
    if(l==n && r==n){
        if(d<2 || u<2) return false;
    }
    
    if(u==n-1 || d==n-1){
        if(l+r<1) return false;
    }
    if(l==n-1 || r==n-1){
        if(d+u<1) return false;
    }

    if(u==n-1 && d==n-1){
        if(l+r<2) return false;
    }
    if(l==n-1 && r==n-1){
        if(d+u<2) return false;
    }

    if((u==n && d==n-1) || (u==n-1 && d==n)){
        if(l+r<3) return false;
    }
    if((l==n && r==n-1) || (l==n-1 && r==n)){
        if(u+d<3) return false;
    }

   return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int u, d, r, l, n;
        cin>>n>>u>>r>>d>>l;
        if(check(n, u, r, d, l)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
