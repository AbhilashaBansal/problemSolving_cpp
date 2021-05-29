#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// number theory: O(n) solution

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        int n;
        cin>>n;

        map <int, ll> um;
        ll ans=0;
        ll prev=0;
        for(int i=0; i<n; i++){
            int x; cin>>x;
            // consider the contributions of all subarrays ending at index i
            // contributions of subarrays ending at i-1 will be added as it is
            // new conributions can be cause of previously present elements with value x
            // suppose, x is present at some j (j<i obv), uska contribution kitni subarrays me aaega ? => j+1 subarrays me (think starting index)
            // to har presence of x ke liye, j+1 add karna padega current value me
            // isko cumulaive sum banake 1 bucket me store karne ka, taki O(1) me kaam ho jaaye
            // yani overall solution O(n)
            ll cur = prev + um[x];

            // memory wise bhi optimized hai
            // dp array banake sum karne ki jagah, haathon haath add + replace kar diya & 2 buckets me kaam done
            ans += cur;
            prev = cur;
    
            um[x] += (i+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
