#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>

// Rainwater Trapping / Harvesting
// Time: O(N), Space: O(N)

ll max_rainwater(int arr[], int n){
        int *left = new int[n];
        int *right = new int[n];
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], arr[i]);
        }
        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1], arr[i]);
        }
        
        ll ans=0;
        for(int i=0; i<n; i++){
            ans += min(left[i], right[i])-arr[i];
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
        int *a = new int[n];
        for(int i=0; i<n; i++) cin>>a[i];  

        cout<<max_rainwater(a, n)<<endl;      
    }
    return 0;
}
