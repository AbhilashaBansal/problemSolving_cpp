// greedy problem, based on fact
// sum of deviations from median is minimum, provided signs are ignored

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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt = 0;
        map <int, int> pos;
        for(int i=0; i<n; i++){
            if(s[i]=='.') continue;
            pos[++cnt] = i+1;
        }

        if(cnt==0){
            cout<<"0\n";
            continue;
        }
        int cent_sheep = (cnt+1)/2;
        int xcoor = pos[cent_sheep];
        ll ans = 0;
        for(auto p: pos){
            ans += abs(xcoor-p.second) - abs(cent_sheep-p.first);
        }
        cout<<ans<<endl;
    }
    return 0;
}
