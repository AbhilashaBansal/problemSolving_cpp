#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// greedy problem
// using multi set or priority queue (heap)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int* a = new int[n];

    multiset <int> ms;
    ll sm=0, cnt=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(sm+a[i]>=0){
            // can include it
            sm += a[i];
            cnt++;
            if(a[i]<0){
                ms.insert(a[i]);
            }
        }
        else{
            // find the most negative element we have incl till now, and replace it for current one, if its less negative
            int ele = *ms.begin();
            if(ele < a[i]){
                ms.erase(ms.begin());
                ms.insert(a[i]);
                sm -= ele;
                sm += a[i];
            }
        }
    }

    cout<<cnt<<endl;
    return 0;
}
