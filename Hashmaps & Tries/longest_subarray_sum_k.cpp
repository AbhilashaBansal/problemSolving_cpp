#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int longestSubSumK(int a[], int n, int k=0){
    unordered_map <int, int> m;
    ll pre=0; 
    int len=0;
    m[0]=-1;

    // pre[j]-pre[i] = k;
    // pre[i] = pre[j]-k;

    for(int i=0; i<n; i++){
        pre += a[i];
        if(m.count(pre-k)){
            len = max(len, i-m[pre-k]);
        }
        if(m.count(pre)==0){
            m[pre]=i;
        }
    }

    return len;
}

int main() {
    int n, k;
    cin>>n>>k;

    int *a = new int[n];
    for(int i=0; i<n; i++) cin>>a[i];
    
    cout<<longestSubSumK(a, n, k);
    return 0;
}
