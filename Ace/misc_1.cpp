// seemingly DP, but actually BFS w/ array elements as nodes!!!
// O(N)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[1000005];
        for(int i=0; i<n; i++) cin>>a[i];

        bool *vis = new bool[n]{0};
        int *dist = new int[n]{INT_MAX};
        vis[0] = true;
        dist[0] = 0;
        queue <int> q;
        q.push(0);
        int ans=-1;
        //BFS
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            if(a[idx]==0){
                ans = dist[idx];
                break;
            }
            int peeche = idx-a[idx];
            int aage = idx+a[idx];
            if(peeche>=0 && !vis[peeche]){
                q.push(peeche);
                vis[peeche] = true;
                dist[peeche] = dist[idx]+1;
            }
            if(aage<n && !vis[aage]){
                q.push(aage);
                vis[aage] = true;
                dist[aage] = dist[idx]+1;
            }
        }
        cout<<ans<<endl;
    }   
    return 0;
}
