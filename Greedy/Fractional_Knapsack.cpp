// standard Fractional Knapsack Problem (greedy approach)
// O(nlogn)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Item{
    public:
    int wt, val;
    float ratio;
    Item (int w, int v){
        wt = w;
        val = v;
        ratio = (1.0*v)/w;
    }
};

bool comp(Item i1, Item i2){
    return i1.ratio > i2.ratio;
}

double fractional_KS(vector<pair<int, int>>& items, int n, int w) {
    // ITEMS contains {weight, value} pairs
    vector <Item> v;
    for(int i=0; i<n; i++){
        Item it(items[i].first, items[i].second);
        v.push_back(it);
    }
    sort(v.begin(), v.end(), comp);

    int cap = w;
    double prof=0.0;
    int i;
    for(i=0; i<n; i++){
        if(v[i].wt<=cap){
            cap -= v[i].wt;
            prof += v[i].val;
        }
        else break;
    }
    if(i<n && cap){
        prof += (v[i].ratio*cap);
    }

    return prof;
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
        int capacity; 
        cin>>capacity;
        vector <pair<int,int> > v(n);
        for(int i=0; i<n; i++){
            int wt; cin>>wt;
            v[i].first = wt;
        }
        for(int i=0; i<n; i++){
            int val; cin>>val;
            v[i].second = val;
        }

        cout<<fixed<<setprecision(2)<<fractional_KS(v, n, capacity)<<endl;
    }
    return 0;
}
