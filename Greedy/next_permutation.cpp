#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// next permutation
// greedy solution
// O(N)

void nextPermutation(vector<int>& permutation) {
    int n = permutation.size();
    int i = n-1;
    while(i>=1 && permutation[i]<=permutation[i-1]){
        i--;
    }

    if(i==0){
        // no lexicographically greater permutation possible
        reverse(permutation.begin(), permutation.end());
        return;
    }

    // 7 8 6 3 5 4 2 1
    int ele = permutation[i-1]; // 3, first element from right that is smaller than next element

    // pehle swap, fir reverse karna tha
    // 7 8 6 4 5 3 2 1 --> 7 8 6 4 1 2 3 5
    // par upper_bound ke liye sorted array chahiye thi, isliye pehle reverse karke fir upper_b laga diya
    // no diff, same result
    reverse(permutation.begin()+i, permutation.end());

    // index of element that is just greater than ele, jissey swap karenge
    int swap_idx = upper_bound(permutation.begin()+i, permutation.end(), permutation[i-1])-permutation.begin();
    swap(permutation[i-1], permutation[swap_idx]);    
    return;
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
        vector<int> permutation(n);
        for(int i=0; i<n; i++) cin>>permutation[i];

        nextPermutation(permutation);
        for(int ele: permutation){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
