// TREE BFS (pattern similar to House Robber Tree problem)
// O(N) solution, N = no of nodes in tree

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(int src, int par, vector<int> adj[], vector <ll> dp[], vector<ll> &left, vector<ll> &right){
    for(int child: adj[src]){
        if(child!=par){
            dfs(child, src, adj, dp, left, right);
        }
    }

    for(int child: adj[src]){
        if(child!=par){
            // isko left pe set karein to
            dp[src][0] += max(abs(left[src-1]-left[child-1])+dp[child][0], abs(left[src-1]-right[child-1])+dp[child][1]);
            // isko right pe set karein to
            dp[src][1] += max(abs(right[src-1]-left[child-1])+dp[child][0], abs(right[src-1]-right[child-1])+dp[child][1]);
        }
    }
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
        vector <ll> left(n);
        vector <ll> right(n);
        for(int i=0; i<n; i++){
            cin>>left[i]>>right[i];
        }

        vector <int> adj[n+1];
        for(int i=1; i<=n-1; i++){
            int x, y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector <ll> values[n+1];
        for(int i=0; i<=n; i++){
            values[i] = {0, 0};
        }
        dfs(1, 1, adj, values, left, right);
        cout<<max(values[1][0], values[1][1])<<endl;
    }
    return 0;
}
