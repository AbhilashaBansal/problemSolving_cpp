#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
 
bool isBoundary(int x, int y, int n, int m){
    if(x==0 || x==n-1 || y==0 || y==m-1) return true;
    return false;
}
 
string path(vector<vector<char>> &mat, int n, int m, map<pii, pii> &parent, int x, int y){
    string ans="";
 
    pii cur = make_pair(x, y);
    while(parent[cur]!=cur){
        pii par = parent[cur];
        // cout<<cur.first<<"-"<<cur.second<<endl;
        int px = par.first;
        int py = par.second;
        if(cur.first-px==1){
            ans+='D';
        }
        else if(cur.first-px == -1){
            ans+='U';
        }
        else if(cur.second-py==1){
            ans+='R';
        }
        else{
            ans+='L';
        }
        cur = parent[cur];
    }
    // cout<<cur.first<<"-"<<cur.second<<endl;
 
    reverse(ans.begin(), ans.end());
    // cout<<ans<<endl;
    return ans;
}
 
string bfs(vector<vector<char>> &mat, int n, int m, int x, int y, vector<vector<int>> &monst_dist){
 
    queue <pii> q;
    q.push(make_pair(x, y));

    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    map<pii, pii> parent;

    vis[x][y] = true;
    dist[x][y] = 0;
    parent[make_pair(x,y)] = make_pair(x, y);
 
    while(!q.empty()){
        pii front = q.front();
        q.pop();
        
        if(isBoundary(front.first, front.second, n, m)){
            return path(mat, n, m, parent, front.first, front.second);
        }
 
        for(int i=0; i<4; i++){
            int xx = front.first + dx[i];
            int yy = front.second + dy[i];
 
            if(xx<0 || yy<0 || xx>=n || yy>=m) continue;
 
            int iska_dist = dist[front.first][front.second]+1;
            if(vis[xx][yy]==false && mat[xx][yy]=='.' && iska_dist < monst_dist[xx][yy]){
                q.push(make_pair(xx, yy));
                parent[make_pair(xx, yy)] = make_pair(front.first, front.second);
                vis[xx][yy] = true;
                dist[xx][yy] = iska_dist;
            }
        }
    } 
    return "-1";
}

vector<vector<int>> monster_bfs(vector<vector<char>> &mat, int n, int m){
    queue<pii> q;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]=='M'){
                q.push(make_pair(i, j));
                vis[i][j] = true;
                dist[i][j] = 0;
            }
        }
    }
    
    while(!q.empty()){
        pii front = q.front();
        q.pop();

        // to be done over entire grid, all cells, so no check
        for(int i=0; i<4; i++){
            int xx = front.first + dx[i];
            int yy = front.second + dy[i];
 
            if(xx<0 || yy<0 || xx>=n || yy>=m) continue;
 
            if(vis[xx][yy]==false && mat[xx][yy]!='#'){
                q.push(make_pair(xx, yy));
                vis[xx][yy] = true;
                dist[xx][yy] = dist[front.first][front.second] + 1;
            }
        }
    }

    return dist;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin>>n>>m;
 
    int x, y;
    vector<vector<char>> mat (n, vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
            if(mat[i][j]=='A'){
                x=i, y=j;
            }
        }
    }
    
    vector<vector<int>> dist = monster_bfs(mat, n, m);
    string pth = bfs(mat, n, m, x, y, dist);
    if(pth=="-1") cout<<"NO\n";
    else{
        cout<<"YES\n";
        cout<<pth.length()<<"\n";
        cout<<pth<<endl;
    }
    return 0;
}
