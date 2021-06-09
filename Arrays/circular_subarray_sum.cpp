#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>

// MAX CIRCULAR SUBARRAY SUM
// using Kadane's Algorithm 
// time: O(N), space: O(1)

int max_Circular_Subarray_Sum(int arr[], int n){
        
    int neg=0;
    int max_ele = INT_MIN;
    
    int cur1=0, tot=0, cur2=0, maxsm=arr[0], minsm=arr[0];
    
    for(int i=0; i<n; i++){
        if(arr[i]<0) neg++;
        max_ele = max(max_ele, arr[i]);
        
        tot+=arr[i];
        cur1+=arr[i];
        cur2+=arr[i];
        
        maxsm=max(maxsm, cur1);
        if(cur1<0) cur1=0;
        
        minsm=min(minsm, cur2);
        if(cur2>0) cur2=0;
    }
    
    // handle case when all elements are negative, separately
    if(neg==n) return max_ele;
    
    int op2 = tot-minsm;
    return max(maxsm, op2);
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
        int* a = new int[n];
        for(int i=0; i<n; i++) cin>>a[i];

        cout<<max_Circular_Subarray_Sum(a, n)<<" ";
    }

    return 0;
}
