#include<bits/stdc++.h>
using namespace std;

#define pp pair<int,pair<int,int>> 
//In this pair, first int represents the element, next two int represents its position in 2d vector ie. i,j

vector<int> merge_k_sorted_arrays(vector<vector<int>> arr, int k) {

    priority_queue<pp, vector<pp>, greater<pp> > pq;
    vector <int> ans;

    for(int i=0; i<k; i++){
        pq.push({arr[i][0],{i,0}}); //Pushing the first element of all K sorted arrays in the priority queue
    }

    while(!pq.empty()) {
        pp front=pq.top();
        pq.pop();
        ans.push_back(front.first);
        int id=front.second.first;
        int j=front.second.second;
        if(j+1<arr[id].size())
            pq.push({arr[id][j+1],{id,j+1}});
    }
    
    return ans;
}

int main() {
    int k,n;
    cin>>k>>n;

    vector<vector<int>> arr(k,vector<int>(n)); //Storing k sorted arrays in a 2d vector
    for(int i=0;i<k;i++) {
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }

    vector <int> output = merge_k_sorted_arrays(arr, k);
    for(auto ele:output)
        cout<<ele<<" ";
	return 0;
}
