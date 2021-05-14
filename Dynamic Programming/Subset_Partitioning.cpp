#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// subset partitioning
// O(sum x N) solution

// space: O(N x sum)
bool SubsetSum(vector<int> &arr, int n, ll target, vector<vector<int>> &dp){
    // base cases
	if(target==0) return dp[target][n]=1;
    if(n==0) return dp[target][n]=0;
    
    // memoisation
    if(dp[target][n]!=-1) return dp[target][n];
    
    // do not include this element
    dp[target][n] = SubsetSum(arr, n-1, target, dp);

    // include this element
    if(arr[n-1]<=target){
        dp[target][n] |= SubsetSum(arr, n-1, target-arr[n-1], dp);
    }
    
    return dp[target][n];
}

// space optimized bottom up solution
// we only require the values of previous row, that is, 
// possiblity of reaching target (ranging from 0...sm) by using only elements up till index (i-1)
// time: O(N x sum)
// but space; O(sm)
bool SubsetSum_BotUp(vector<int> &arr, int n, ll target){
    vector <int> dp(target+1, 0);
    dp[0] = 1;
    
    for(int i=0; i<n; i++){
        // go in reverse order, cause previous / earlier values will be required in this iteration
        // if we update them first, result will be wrong !
        for(int j=target; j>=1; j--){
            // not valid if negative numbers also present
            if(arr[i]<=j){
                dp[j] |= dp[j-arr[i]];
            }
        }
    }
    return dp[target];
}

bool canPartition(vector<int> &arr, int n) {
    ll sm=0;
    for(int ele: arr){
        sm += ele;
    }
    if(sm%2==1) return false;
    
    // vector<vector<int>> dp(sm/2+1, vector<int>(n+1, -1));
    // return SubsetSum(arr, n, sm/2, dp);
    return SubsetSum_BotUp(arr, n, sm/2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    cout<<canPartition(v, n);
    return 0;
}
