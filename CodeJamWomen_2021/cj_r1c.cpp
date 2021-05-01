// O(nlogn) soln, CODE JAM 2021 Round 1C, Q1

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        ll n, k;
        cin>>n>>k;
        vector <ll> v(n);
        for(int i=0; i<n; i++) {
            cin>>v[i];
        }

        sort(v.begin(), v.end());
        float ans = 0.0;
        vector <ll> intervals;

        int left=0, right=0;
        
        left = v[0]-1;
        right = k-v[n-1];
        intervals.push_back(left);
        intervals.push_back(right);
        vector<int>v2;
        
        for(int i=0; i<=n-2; i++){
            if(v[i]==v[i+1] || v[i]+1==v[i+1]){
                continue;
            }
            int temp = v[i+1]-1-v[i];
            int temp2 = (temp+1)/2;
            if(temp>1){
                v2.push_back(temp);
            }
            
            intervals.push_back(temp2);
        }

        sort(intervals.begin(), intervals.end(), greater<int>());
        sort(v2.begin(), v2.end(), greater<int>());

        if(intervals.size()>=2){
           ans += ((intervals[1]*1.00)/k);
        }
        if(intervals.size()>=1){
            ans += ((intervals[0]*1.00)/k);
        }
        
        for(auto ele: v2){
            float ta = (ele*1.00)/k;
            ans = max(ans, ta);
        }
       
        cout<<"Case #"<<cnt++<<": "<<fixed<<setprecision(6)<<ans<<endl;
    }
    return 0;
}
