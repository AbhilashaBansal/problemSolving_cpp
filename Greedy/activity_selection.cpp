// Activity Selection (std greedy problem)
// O(nlogn)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool comp(pair<int,int> p1, pair<int,int> p2){
    return p1.second<p2.second;
}

int maximumActivities(vector<int> &start, vector<int> &finish){

    vector<pair<int, int> > s_e(start.size());
    for(int i=0; i<start.size(); i++){
        s_e[i] = make_pair(start[i], finish[i]);
    }
    // sorting basis end times (greedy approach)
    sort(s_e.begin(), s_e.end(), comp);
    
    int prev_end=0, ans=0;
    for(int i=0; i<start.size(); i++){
        if(prev_end<=s_e[i].first){
            ans++;
            prev_end = s_e[i].second;
        }
    }
    return ans;
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
        vector<int> start(n), end(n);
        for(int i=0; i<n; i++){
            cin>>start[i];
        }
        for(int i=0; i<n; i++){
            cin>>end[i];
        }
        cout<<maximumActivities(start, end)<<endl;
    }
    return 0;
}
