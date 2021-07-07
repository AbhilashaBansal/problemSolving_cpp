#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>

vector<int> topol (vector<vector<int>> &adj, vector<int> &ind, int n){
    vector<int> res;

    queue<int> q;
    for(int i=0; i<n; i++){
        if(ind[i]==0) q.push(i);
    }

    while(!q.empty()){
        int ele = q.front();
        q.pop();
        res.push_back(ele);

        for(int nbr: adj[ele]){
            ind[nbr]--;
            if(ind[nbr]==0){
                q.push(nbr);
            }
        }
    }
    
    return res;
}

void fn(vector<vector<int>> &adj, vector<int> &topo, int n){
    // largest dist nikalna hai, to init with int_min
    vector<int> dist(n, INT_MIN);
    vector<int> par(n);
    par[0]=0;
    dist[0]=0;

    for(int i=0; i<topo.size(); i++){
        int ele = topo[i];
        for(int nbr: adj[ele]){
            if(dist[nbr]<(dist[ele]+1)){
                dist[nbr] = dist[ele]+1;
                par[nbr] = ele;
            }
        }
    }

    if(dist[n-1]<0){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    
    vector<int> path;
    int ele=n-1;
    while(par[ele]!=ele){
        path.push_back(ele);
        ele = par[ele];
    }
    path.push_back(0);

    cout<<path.size()<<"\n";
    for(int i=path.size()-1; i>=0; i--){
        cout<<path[i]+1<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    vector<int> ind(n, 0);

    while(m--){
        int x, y;
        cin>>x>>y;
        x--, y--;
        adj[x].push_back(y);
        ind[y]++;
    }

    // fn call
    vector <int> topo = topol(adj, ind, n);

    fn(adj, topo, n);
    return 0;
}