// SHORTEST PATH REVISITED

// Fortunately, to our rescue we have K special offers, which means while travelling from City 1 to any other city we can select at-most K roads and we will not be charged for using those roads. 


// Find the shortest path from 0 to every other node, given that we can skip 

#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include<algorithm>
using namespace std;

int main() {
	int n, m, k;
	cin>>n>>m>>k;

	vector<vector<pair<int, int> > > adj(n);

	for(int i=1; i<=m; i++){
		int a, b, wt;
		cin>>a>>b>>wt;

		a--;
		b--;
		adj[a].push_back(make_pair(b, wt));
		adj[b].push_back(make_pair(a, wt));
	}

	// src is 0
	vector<vector<int> > dist(n, vector<int>(k+1, INT_MAX));
	set<pair<int, pair<int, int> > > sttt;

	sttt.insert({0, {0, 0}});

	while(!sttt.empty()){
		pair<int, pair<int, int> > pr = *sttt.begin();
		sttt.erase(pr);

		int node = pr.second.second;
		int d = pr.first;
		int offersUsed = pr.second.first;

		dist[node][offersUsed] = d;

		for(auto nbr: adj[node]){
			// donot use an offer
			int nayaDist = d + nbr.second;
			int puranaDist = dist[nbr.first][offersUsed];
			if(nayaDist<puranaDist){
				if(sttt.find({puranaDist, {offersUsed, nbr.first}})!=sttt.end()){
					sttt.erase(sttt.find({puranaDist, {offersUsed, nbr.first}}));
				}

				sttt.insert({nayaDist, {offersUsed, nbr.first}});
				dist[nbr.first][offersUsed] = nayaDist;
			}

			// use an offer
			if(offersUsed<k){
				int nayaDist2 = d;
				int puranaDist2 = dist[nbr.first][offersUsed+1];
				if(nayaDist2<puranaDist2){
					if(sttt.find({puranaDist2, {offersUsed+1, nbr.first}})!=sttt.end()){
						sttt.erase(sttt.find({puranaDist2, {offersUsed+1, nbr.first}}));
					}

					sttt.insert({nayaDist2, {offersUsed+1, nbr.first}});
					dist[nbr.first][offersUsed+1] = nayaDist2;
				}
			}
		}
	}

	for(int i=0; i<n; i++){
		cout<<*min_element(dist[i].begin(), dist[i].end())<<" ";
	}
	cout<<"\n";
	return 0;
}
