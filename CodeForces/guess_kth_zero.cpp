// Interactive Problem
// based on Binary Search

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// [ 1,0,1,1,0,1 ]

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, k;
    cin>>n>>t>>k;
    int s=0, e=n-1;
    int sm = k;
    int ele;
    int posans = -1;
    while(s<=e){
        int mid = (s+e)/2;
        cout<<"? "<<s+1<<" "<<mid+1<<endl;
        cin>>ele;
        int comp = (mid-s+1)-ele;
        if(comp==sm){
            posans = mid+1;
            e = mid-1;
        }
        if(comp<sm){
            sm-=comp;
            s = mid+1;
        }
        else if(comp>sm){
            e = mid-1;
        }
    }
    cout<<"! "<<posans<<endl;
    return 0;
}
