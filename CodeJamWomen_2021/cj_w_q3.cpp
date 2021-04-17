#include <bits/stdc++.h>
using namespace std;

// INTRODUCTION SESSIONS 
// brute force, only for 1st Test Case, doesn't take into account parallel transactions

int fn(int x, int y, vector< vector<char> > v, int m, int n, vector<int> &instack){
    // cout<<x<<"-"<<y<<" ";
    if(v[x][y]=='Y') return 0;

    instack[x] = instack[y] = 1;

    vector <int> xman;
    vector <int> yman;
    for(int i=0; i<m; i++){
        if(instack[i]!=1 && v[x][i]=='Y'){
            xman.push_back(i);
        }
        if(instack[i]!=1 && v[y][i]=='Y'){
            yman.push_back(i);
        }
    }
    if(yman.size()==0 ||xman.size()==0) {
        instack[x] = instack[y] = 0;
        return -1;
    }

    int small_ans=INT_MAX;
    for(int j=0; j<xman.size(); j++){
        bool fl=false;
        for(int k=0; k<yman.size(); k++){ 
            int tmp = fn(xman[j], yman[k], v, m, n, instack);
            if(xman[j]==yman[k]){
                small_ans=0;
                fl=true;
                break;
            }
            else if(tmp!=-1 && tmp+1<small_ans){
                small_ans = tmp+1;
            }
        }
        if(fl) break;
    }

    instack[x] = instack[y] = 0;
    if(small_ans==INT_MAX){
        return -1;
    }
    return small_ans+1;
}

int main(){
    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        int n, m, p;
        cin>>m>>n>>p;

        vector< vector<char> > v(m+n, vector<char>(m+n));
        vector<int> instack(m+n, 0);
        for(int i=0; i<m+n; i++){
            for(int j=0; j<m+n; j++){
                cin>>v[i][j];
            }
        }

        vector <int> ans(p);
        
        for(int i=0; i<p; i++){
            int x, y;
            cin>>x>>y;
            x--, y--;
            if(v[x][y]=='Y') ans[i]=0;
            else ans[i] = fn(x, y, v, m, n, instack);
        }
        
        cout<<"Case #"<<cnt++<<": ";
        for(auto ele: ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}