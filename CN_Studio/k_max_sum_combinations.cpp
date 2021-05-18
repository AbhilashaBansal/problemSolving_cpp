#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, pair<int, int>>

// K max sum combinations
// O(nlogn + klogk) solution (use whichever is max)

class comp{
    public:
    bool operator () (pii a, pii b){
        return a.first<b.first; // by default max heap hota hai
    }
};

vector<int> kMaxSumCombination(vector<int>&a, vector<int>&b, int n, int k){
    set <pair<int,int>> s;
    vector<int> ans;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    priority_queue <pii, vector<pii>, comp> pq;
    pq.push({a[0]+b[0], {0, 0}});
    s.insert({0, 0});
    
    while(k--){
        pii p = pq.top();
        pq.pop();
        
        ans.push_back(p.first);
        int i = p.second.first;
        int j = p.second.second;
        // cout<<i<<" "<<j<<" --> ";
        if(i+1<n){
            if(s.find({i+1,j})==s.end()){
            	pq.push({a[i+1] + b[j], {i+1, j}});
                s.insert({i+1, j});
            }
        }
        if(j+1<n){
            if(s.find({i, j+1})==s.end()){
                s.insert({i, j+1});
            	pq.push({a[i] + b[j+1], {i, j+1}});
            }
        }
    }
	return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    int k; cin>>k;
    vector <int> a(n);
    vector <int> b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    vector <int> ans = kMaxSumCombination(a, b, n, k);
    for(int ele: ans) cout<<ele<<" ";
    return 0;
}
