// CF: E - MINIMUM PATH

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>
#define pll pair<ll,ll>
#define pb push_back
#define YES cout<<"Yes \n"
#define NO cout<<"No \n"
#define mod (ll)(1e9+7)


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;   
    // cin>>t;
    int cnt=1;
    while(t--){
        ll n, m;
        cin>>n>>m;

        vector<vector<pair<int, ll> > > adj(n);

        for(int i=0; i<m; i++){
            ll u, v, wt;
            cin>>u>>v>>wt;

            u--, v--;

            adj[u].pb({v, wt});
            adj[v].pb({u, wt});
        }

        vector<vector<vector<ll> > > dist(n, vector<vector<ll> >(2, vector<ll>(2ll, LLONG_MAX)));
	    set<pair<ll, vector<int> > > sttt;

	    sttt.insert({0ll, {0, 0, 0}});

        while(!sttt.empty()){
            pair<ll, vector<int> > pr = *sttt.begin();
		    sttt.erase(pr);

		    int node = pr.second[0];
		    ll d = pr.first;
            vector<int> v = pr.second;
            int added = v[1];
            int subtracted = v[2];

            dist[node][added][subtracted] = d;

            for(auto nbr: adj[node]){
                // donot add / subtract edge
                ll nayaDist = d + nbr.second;
                ll puranaDist = dist[nbr.first][added][subtracted];
                if(nayaDist<puranaDist){
                    if(sttt.find({puranaDist, {nbr.first, added, subtracted}})!=sttt.end()){
                        sttt.erase(sttt.find({puranaDist, {nbr.first, added, subtracted}}));
                    }

                    sttt.insert({nayaDist, {nbr.first, added, subtracted}});
                    dist[nbr.first][added][subtracted] = nayaDist;
                }

                // only add 
                if(added==0){
                    ll nayaDist2 = d + 2*nbr.second;
                    ll puranaDist2 = dist[nbr.first][1][subtracted];
                    if(nayaDist2<puranaDist2){
                        if(sttt.find({puranaDist2, {nbr.first, 1, subtracted}})!=sttt.end()){
                            sttt.erase(sttt.find({puranaDist2, {nbr.first, 1, subtracted}}));
                        }

                        sttt.insert({nayaDist2, {nbr.first, 1, subtracted}});
                        dist[nbr.first][1][subtracted] = nayaDist2;
                    }
                }

                // only subtract
                if(subtracted==0){
                    ll nayaDist2 = d;
                    ll puranaDist2 = dist[nbr.first][added][1];
                    if(nayaDist2<puranaDist2){
                        if(sttt.find({puranaDist2, {nbr.first, added, 1}})!=sttt.end()){
                            sttt.erase(sttt.find({puranaDist2, {nbr.first, added, 1}}));
                        }

                        sttt.insert({nayaDist2, {nbr.first, added, 1}});
                        dist[nbr.first][added][1] = nayaDist2;
                    }
                }

                // both add & subtract edge
                if(added==0 && subtracted==0){
                    ll nayaDist2 = d + nbr.second;;
                    ll puranaDist2 = dist[nbr.first][1][1];
                    if(nayaDist2<puranaDist2){
                        if(sttt.find({puranaDist2, {nbr.first, 1, 1}})!=sttt.end()){
                            sttt.erase(sttt.find({puranaDist2, {nbr.first, 1, 1}}));
                        }

                        sttt.insert({nayaDist2, {nbr.first, 1, 1}});
                        dist[nbr.first][1][1] = nayaDist2;
                    }
                }
            }
        }

        for(int i=1; i<n; i++){
            cout<<dist[i][1][1]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
