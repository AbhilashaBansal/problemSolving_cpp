// 2 pointer approach (tricky to figure out !!!)
// O(n)

#include <bits/stdc++.h>
using namespace std;

int maxDiff (vector<int> &a, int n) {	
	vector<int> max_from_right(n);
    max_from_right[n-1] = a[n-1];
    for(int i=n-2; i>=0; i--){
        if(max_from_right[i+1]<a[i]){
            max_from_right[i] = a[i];
        }
        else max_from_right[i] = max_from_right[i+1];
    }
    
    int max_diff = 0;
    int i=0, j=0;
    while(i<n && j<n){
        if(a[i]<=max_from_right[j]){
            max_diff = max(max_diff, j-i);
            j++;
        }
        else{
            i++;
        }
    }
	return max_diff;
}


int main() {
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    cout<<maxDiff(v, n);
    return 0;
}
