// SAVE DOLBY 
// BFS & DFS on IMPLICIT GRAPH
// O(no of elements in matrix, ie, no of nodes) = O(nm)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

queue <pair<int,int> > q;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// O(nm)
void DFS(vector <vector<int> > &v, int n, int m, int i, int j, vector <vector<int> > &dist){
    if(i<0 || i>=n || j<0 || j>=m) return;
    if(v[i][j]!=1) return;

    // self work
    v[i][j] = -1; // to differentiate
    q.push(make_pair(i, j)); // potential starting point for BFS call to find shortest distance
    dist[i][j] = 0;

    // recursive work
    for(int k=0; k<4; k++){
        DFS(v, n, m, i+dx[k], j+dy[k], dist);
    }
}

// O(nm)
int BFS(vector <vector<int> > &v, int n, int m, vector <vector<int> > &dist){
    int global_ans = INT_MAX;

    while(!q.empty()){
        auto p = q.front();
        int i = p.first;
        int j = p.second;
        q.pop();
        // check if this is member of 2nd element
        if(v[i][j]==1){
            global_ans = min(global_ans, dist[i][j]);
        }

        // adding neighbours in queue
        for(int k=0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(x<0 || x>=n || y<0 || y>=m) continue;

            if(dist[x][y]==INT_MAX){
                // not present in queue already
                q.push(make_pair(x, y));
                dist[x][y] = dist[i][j] + 1;
            }
        }
    }

    return global_ans;
}

int func(vector <vector<int> > &v, int n, int m){
    vector <vector<int> > dist (n, vector<int>(m, INT_MAX));

    // finding first island
    bool flag = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]==1){
                // found the first one of an island
                // find entire island and then assign all elements some spl sign, to not confuse it w/ 2nd (destination) island
                DFS(v, n, m, i, j, dist);
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    // finding shortest dist starting from elements present in queue rn
    // BFS call
    int ans = BFS(v, n, m, dist);
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++) cout<<dist[i][j]<<" ";
    //     cout<<endl;
    // }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector <vector<int> > v(n, vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    // fn call
    int ans = func(v, n, m);
    cout<<ans-1<<endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
