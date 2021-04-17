#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        int n;
        cin>>n;
        vector <int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        int cur=1, total = 1, prev_ele = v[0];
        for(int i=1; i<n; i++){
            if(v[i]==prev_ele){
                total += cur;
            }
            else{
                prev_ele = v[i];
                cur++;
                total+=cur;
            }
        }
        cout<<"Case #"<<cnt++<<": "<<total<<endl;
    }
    return 0;
}