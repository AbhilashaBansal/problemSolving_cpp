#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>

void update(string &s, int idx, vector<int> &v){
    // cout<<idx<<"- ";
    if(idx<0) return;
    int child1 = 2*idx+1;
    int child2 = 2*idx+2;
    int par = (idx-1)/2;

    if(child1>=v.size()){
        // level 1 initialization
        v[idx]= s[idx]=='?'?2:1;
    }
    else{
        if(s[idx]=='0') v[idx] = v[child2];
        else if(s[idx]=='1') v[idx] = v[child1];
        else v[idx] = v[child1] + v[child2];
    }
    if(idx==0) return;
    update(s, par, v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin>>k;
    string s;
    cin>>s;
    reverse(s.begin(), s.end());

    int tot = pow(2,k)-1;
    vector<int> v(tot);
    
    for(int i=0; i<pow(2,k-1); i++){
        // agar ek index hai, to winner 1
        // else ? hai, to 2 potential winners
        v[tot-1-i]= s[tot-1-i]=='?'?2:1;
    }
    for(int i=tot-1-pow(2, k-1); i>=0; i--){
        // 0 based indexing ke acc children
        int child1 = 2*i+1;
        int child2 = 2*i+2;
        if(s[i]=='0') v[i] = v[child2];
        else if(s[i]=='1') v[i] = v[child1];
        else v[i] = v[child1] + v[child2];
    }

    // for(int x: v) cout<<x<<" ";

    int q; cin>>q;
    while(q--){
        int idx;
        char c;
        cin>>idx>>c;
        idx--;
        s[tot-1-idx] = c;
        update(s, tot-1-idx, v);
        // cout<<s<<" ";
        cout<<v[0]<<endl;
    }

    return 0;
}
