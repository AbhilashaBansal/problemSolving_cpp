// Job Scheduling/ Sequencing (std greedy problem)

// one approach (w/o set, linearly iterating to check if a time slot is available) : O(n^2)
// 2nd approach (use set to find if a slot within deadline is available or not) : O(n log(max_time_slot))

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll jobSchedule(vector<int> deadline, vector<int> profit, int N) {
    // set to store all possible time slots available currently
    set <int> time;
    for(int i=1; i<=N; i++){
        time.insert(i);
    }
    
    vector<pair<int,int>> jobs(N);
    for(int i=0; i<N; i++){
        jobs[i] = make_pair(profit[i], deadline[i]);
    }
    sort(jobs.begin(), jobs.end());

    ll ans=0;
	for(int i=N-1; i>=0; i--){
        int dead = jobs[i].second;
        int prof = jobs[i].first;
        auto it = time.upper_bound(dead);
        if(it==time.begin()) continue;
        it = prev(it);
        time.erase(it);
        ans += prof;
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
        vector<int> deadline(n), profit(n);
        for(int i=0; i<n; i++){
            cin>>deadline[i]>>profit[i];
        }
        cout<<jobSchedule(deadline, profit, n)<<endl;
    }
    return 0;
}
