// BINARY SEARCH

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPos(int ht, ll min_wood, int a[], int n){
    ll sm=0;
    for(int i=n-1; i>=0; i--){
        if(a[i]<=ht) break;
        sm += (a[i]-ht); 
    }
    if(sm>=min_wood) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    cin>>n;
    int* a = new int[n];
    for(int i=0; i<n; i++) cin>>a[i];
    cin>>x;

    sort(a, a+n);

    int s=0, e=a[n-1];
    int ans=0;
    while(s<=e){
        int mid = (s+e)/2;
        if(isPos(mid, x, a, n)){
            ans = mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }

    cout<<ans;
    return 0;
}
