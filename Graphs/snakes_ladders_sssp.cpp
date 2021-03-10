#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class graph{
    public:
    map <int, list<int>> m;

    void add_edge(int x, int y){
        m[x].push_back(y);
    }

    int bfs(int src, int dest){
        map<int, int> dist;
        map<int, int> parent;
        queue <int> q;

        for(auto p: m){
            int node = p.first;
            dist[node]=INT_MAX;
            parent[node]=node;
        }
        q.push(src);
        dist[src]=0;

        while(!q.empty()){
            int ele = q.front();
            q.pop();

            for(int nbr: m[ele]){
                if(dist[nbr]==INT_MAX){
                    parent[nbr]=ele;
                    dist[nbr]=dist[ele]+1;
                    q.push(nbr);
                }
            }
        }

        // int temp = dest;
        // while(temp!=src){
        //     cout<<temp<<" <- ";
        //     temp = parent[temp];
        // }
        // cout<<src<<endl;
        return dist[dest];
    }

};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, l, s;
        cin>>n>>l>>s;

        int *board = new int[n+1]{0};

        while(l--){
            int x, y;
            cin>>x>>y;
            int len=y-x;
            board[x] +=len;
        }
        while(s--){
            int x, y;
            cin>>x>>y;
            int len=y-x;
            board[x] +=len;
        }

        graph g;
        for(int st=1; st<=n; st++){
            for(int dice=1; dice<=6; dice++){
                int landing = st+dice+board[st+dice];
                if(landing<=n){
                    g.add_edge(st, landing);
                }
            }
        }
        g.add_edge(n, n);

        cout<<g.bfs(1, n)<<endl;
    }
    return 0;
}
