#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>

// Sum of 4 Values
// T: O(N^2 * logN) approach using sorting and auxillary space
// S: O(N^2)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll target;
    cin>>n>>target;
    int *a = new int[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    vector<pair<int, pii>> v;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            v.push_back({a[i]+a[j], {i,j}});
        }
    }

    sort(v.begin(), v.end());
    int v1,v2,v3,v4;
    bool flag=false;

    int s=0, e=v.size()-1;
    while(s<e){
        ll sm = v[s].first+v[e].first;
        if(sm==target){
            v1 = v[s].second.first;
            v2 = v[s].second.second;
            v3 = v[e].second.first;
            v4 = v[e].second.second;
            if(v1!=v3 && v2!=v3 && v1!=v4 && v2!=v4){
                flag=true;
                break;
            }
            else{
                if(v[s+1].first==v[s].first) s++;
                else e--;
            }
        }
        else if(sm>target){
            e--;
        }
        else s++;
    }

    if(!flag){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        vector<int> temp = {v1,v2,v3,v4};
        sort(temp.begin(), temp.end());
        for(auto x: temp) cout<<x+1<<" ";
    }
    
    return 0;
}
