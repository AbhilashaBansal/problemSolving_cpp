#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    
    unordered_map <int, int> mstreak;

    for(int i=0; i<n; i++){
        int no;
        cin>>no;

        if(mstreak.count(no)) continue;
        
        if(mstreak.count(no-1)==0 && mstreak.count(no+1)==0){
            // first element of new streak
            mstreak[no]=1;
        }
        else if(mstreak.count(no-1) && mstreak.count(no+1)){
            // joining two streaks
            int len1 = mstreak[no-1];
            int len2 = mstreak[no+1];
            
            mstreak[no-len1] = len1+len2+1;
            mstreak[no+len2] = len1+len2+1;
            mstreak[no] = len1+len2+1;
        }
        else if(mstreak.count(no-1)){
            // right boundary of streak
            int len1 = mstreak[no-1];

            mstreak[no-len1] = len1+1;
            mstreak[no] = len1+1;
        }
        else{
            // left boundary of a streak
            int len2 = mstreak[no+1];

            mstreak[no] = len2+1;
            mstreak[no+len2] = len2+1;
        }
    }

    int ans=0;
    for(auto it=mstreak.begin(); it!=mstreak.end(); it++){
        ans = max(ans, it->second);
    }
    cout<<ans<<endl;
    return 0;
}
