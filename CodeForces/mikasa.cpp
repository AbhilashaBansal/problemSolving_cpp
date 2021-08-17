#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>

// INTERESTING + TRICKY BITS QUESTION !!!

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        int n, m;
        cin>>n>>m;

        // lets say k present hai
        // n xor x = k, for some 0<=x<=m
        // this means, n xor k = x
        // hume aisa number dhundna hai jo present na ho, lets say z
        // n xor z > m
        // find smallest z, such that n xor z >= m+1
        // ye greedily bit by bit bana sakte hain
        int ans = 0;
        int p = m+1;
        for(int i=30; i>=0; i--){
            int nbit = (n>>i)&1;
            int rhsbit = (p>>i)&1;
            if(nbit==rhsbit){
                // z ko minimize hi karna hai to badiya hai, set this bit to zero
                int no = ~(1<<i);
                ans = ans&no;
            }
            else if(nbit==1 && rhsbit==0){
                // agar hum bit ko 0 set kar dein, z minimise ho jaaega, and xor karke 1 aaega to greater than m+1 bhi ho jaaega for sure
                // to aage ke saare bits 0 set kardo, xor value se fark nahi padega
                int no = ~(1<<i);
                ans = ans&no;
                break;
            }
            else if(nbit==0 && rhsbit==1){
                // must set it to 1
                ans = ans | (1<<i);
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
