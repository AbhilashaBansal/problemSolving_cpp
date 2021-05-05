// number theory
// a[j]-a[i] = j-i
// --> a[j]-j = a[i]-i

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        ll n;
        cin>>n;
        map <ll, ll> fr;
        for(int i=0; i<n; i++){
            ll x; cin>>x;
            x -= i;
            if(fr.count(x)==0){
                fr[x]=0;
            }
            fr[x]++;
        }

        ll ans=0;
        for(auto p: fr){
            ll ele = p.second;
            if(ele>=2){
                ans += ((ele*(ele-1))/2);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
