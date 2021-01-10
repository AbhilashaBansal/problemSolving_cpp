#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int *a = new int[n];
    int *b = new int[n];
    unordered_map <int, int> pos;

    for(int i=0; i<n; i++){
        cin>>a[i];
        pos[a[i]] = 0;
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
        pos[b[i]] = i+1;
    }
    
    if(pos[1]!=0){
        //handling spl case
        int ans=0;
        int stack_idx = pos[1]-1, no=1;
        while(stack_idx<n && b[stack_idx]==no){
            stack_idx++; no++;
        }
        
        // iss stack_index pe ye kram toot gaya
        if(stack_idx==n){
            // agar stack ka end aa gaya tha to chance hai, else not
            int i;
            for(i=no; i<=n; i++){
                if(pos[i]<(i-(no-1))) continue;
                else break;
            }
            if(i==n+1) {
                cout<<pos[1]-1<<endl;
                return 0;
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, pos[i]-i+1+n); //pehle play karna hai, fir draw karna hai, isliye +1
    }
    cout<<ans<<endl;

    return 0;
}
