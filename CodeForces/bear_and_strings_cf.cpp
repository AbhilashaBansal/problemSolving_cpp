#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int l=s.length();
    vector<int> v;
    for(int i=0; i<=l-4; i++){
        if(s.substr(i,4)=="bear"){
            v.push_back(i);
        }
    }

    int cnt=0;
    for(int i=0; i<=l-4; i++){
        int idx = lower_bound(v.begin(), v.end(), i)-v.begin();
        if(idx==v.size()) continue;

        //cout<<v[idx]<<" ";
        cnt += l-v[idx]-3;
        // if(idx!=-1){
        //     idx += i; //current index
        //     cnt += l-idx-3;
        // }
    }
    cout<<cnt<<endl;
    return 0;
}
