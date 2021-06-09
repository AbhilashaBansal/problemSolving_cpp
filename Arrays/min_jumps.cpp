#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>

// MINIMUM JUMPS TO REACH END OF ARRAY
// GREEDY SOLUTION [T: O(N), S: O(1)]

int min_jumps(int A[], int n){
    if(n==1) return 0;
    if(A[0]==0) return -1;
    
    int jumps=1;
    int steps_at_hand = A[0];
    
    // max index that can be reached w/ current indices
    int max_reach = A[0]; 
    
    for(int i=1; i<n; i++){
        // cur jump me hi dest pahoch gaye
        if(i==n-1) return jumps;    
        
        // priority queue me add karne ki jagah aise update karna hai
        max_reach = max(max_reach, A[i]+i);
        steps_at_hand--;
        
        if(steps_at_hand==0) {
            // assume we landed the prev jump at index jaha se max reach tak jaa sakte hain
            // and began a new jump from there
            jumps++;
            steps_at_hand += max_reach-i;
        }

        if(max_reach<i+1) {
            // basically steps_at_hand abhi bhi zero hain !!
            // aage jaa hi nahi sakte   
            return -1;
        }
    }
    
    return -1;
}

// DP Solution [T: O(N^2), S: O(N)]
vector<int> dp;
int min_jumps_DP(int a[], int i, int n){
    if(i==n-1) return dp[i]=0;

    if(dp[i]!=-1) return dp[i];

    dp[i] = INT_MAX;
    for(int j=1; j<=a[i]; j++){
        int smallans = min_jumps_DP(a, i+j, n);
        if(smallans!=-1)
            dp[i] = min(dp[i], smallans+1);
    }

    return dp[i];
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
        int *a = new int[n];
        for(int i=0; i<n; i++) cin>>a[i];

        cout<<min_jumps(a, n)<<endl;
        dp.resize(n);
        for(int i=0; i<n; i++) dp[i]=-1;
        cout<<min_jumps_DP(a, 0, n)<<endl;
    }
    return 0;
}
