#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>

// smallest range in K lists, GFG
// O(nk logk) solution using heaps

pair<int,int> findSmallestRange(vector<vector<int>> arr, int n, int k){
     
    priority_queue <piii, vector<piii>, greater<piii>> pq;
    int max_till_now = INT_MIN;
    
    // insert 1st K potential elements into heap
    for(int i=0; i<k; i++){
        int ele = arr[i][0];
        max_till_now = max(max_till_now, ele);
        pq.push({ele, {i,0}});
    }
    
    int min_range = max_till_now - pq.top().first;
    int start = pq.top().first;
    int end = max_till_now;
    while(true){
        piii top = pq.top();
        pq.pop();
        int arr_no = top.second.first;
        int index = top.second.second;
        if(index+1==n) break;
        
        // nahi to next potential candidate ko daalo
        // and make updations
        int next = arr[arr_no][index+1];
        pq.push({next, {arr_no, index+1}});
        max_till_now = max(max_till_now, next);
        int st = pq.top().first;
        int en = max_till_now;
        if(en-st<min_range){
            // update min range, and start & end points for it
            min_range = en-st;
            end = en;
            start = st;
        }
    }
    
    return make_pair(start, end);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        int n, k;
        cin>>n>>k;

        vector<vector<int>> v(k, vector<int>(n));
        for(int i=0; i<k; i++){
            for(int j=0; j<n; j++){
                cin>>v[i][j];
            }
        }

        pii ans = findSmallestRange(v, n, k);
        cout<<ans.first<<"-"<<ans.second<<endl;
    }
    
    return 0;
}
