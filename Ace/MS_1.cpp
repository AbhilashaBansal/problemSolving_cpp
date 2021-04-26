// Strings + STL implementation 

// O(n^2)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // cin>>t;
    t=1;
    int cnt=1;
    while(t--){
        string s;
        cin>>s;
        string rev = s;
        reverse(rev.begin(), rev.end());

        for(int len=s.length(); len>=1; len--){
            if(s.substr(0, len)==rev.substr(s.length()-len)){
                cout<<rev.substr(0, s.length()-len)<<s<<endl;
                break;
            }
        }
      
        //  TLE w/ this one
        // int ptr=0;
        // while(ptr<=rev.length()-1){
        //     int start = 0;
        //     bool ans = true;
        //     int j;
        //     for(j=ptr; j<=rev.length()-1; j++){
        //         if(s[start++]==rev[j]) continue;
        //         else {
        //             ans = false;
        //             break;
        //         }
        //     }
        //     // either this one matches entirely
        //     if(ans){
        //         // cout<<ptr<<"\n";
        //         string result = rev.substr(0, ptr) + s;
        //         cout<<result<<endl;
        //         break;
        //     }
        //     ptr++;
        // }
    }
    return 0;
}
