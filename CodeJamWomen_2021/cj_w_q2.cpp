#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        int n;
        cin>>n;
        vector <int> l(n);
        for(int i=0; i<n; i++){
            cin>>l[i];
        }

        string ans="A";
        for(int i=0; i<n; i++){
            int terms = l[i];
            if(i%2==0){
                // increasing order 
                char ch = ans[ans.size()-1]+1;               
                while(terms>1){
                    ans+=ch;
                    ch++;
                    terms--;
                }
                if(i==n-1){
                    ans+=ch;
                }
                else{
                    int next = l[i+1];
                    int cur_str = ch-'A';
                    if(next<=cur_str){
                        ans+=ch;
                    } 
                    else{
                        char n = ch + next-cur_str;
                        ans+=n;
                    }
                }
            }
            else{
                // decreasing order
                char ch = 'A' + terms -1;
                while(terms--){
                    ans+=ch;
                    ch--;
                }
            }
        }
        
        cout<<"Case #"<<cnt++<<": "<<ans<<endl;
    }
    return 0;
}