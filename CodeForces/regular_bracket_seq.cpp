#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int l = s.length();
        if(l%2==1){
            cout<<"no\n";
            continue;
        }

        int *a = new int[l]{0};
        int *b = new int[l]{0};
        //int *c = new int[l];
        if(s[0]=='('){
            a[0]=1;
        }
        else if(s[0]==')'){
            b[0]=1;
            cout<<"no\n";
            continue;
        }
        else{
            s[0]='(';
            a[0] = 1;
        }

        for(int i=1; i<l; i++){
            if(s[i]=='(') {
                a[i] = a[i-1]+1;
            }
            else {
                a[i] = a[i-1];
            }
            if(s[i]==')'){
                b[i] = b[i-1] +1;
            }
            else {
                b[i] = b[i-1];
            }
        }

        if(s[l-1]=='?'){
            s[l-1] = ')';
            b[l-1]++;
        }

        int j=0;
        for(j=0; j<l; j++){
            if(s[j]!='?'){
                if(a[j]>=b[j]) continue;
                else break;
            }
            int openb = a[j-1];
            int opena = a[l-1]-a[j-1];
            int closeb = b[j-1];
            int closea = b[l-1]-b[j-1];
            if(openb<closeb) break;
            if(openb==closeb || closea+closeb>=openb+opena){
                s[j]='(';
                for(int k=j; k<l; k++){
                    a[k]++;
                }
                continue;
            }
            else{
                s[j] = ')';
                for(int k=j; k<l; k++){
                    b[k]++;
                }
                continue;
            }
        }
        //cout<<j<<" ";
        // cout<<a[l-1]<<" "<<b[l-1]<<" ";
        if(j==l && a[j-1]==b[j-1]){
            cout<<"yes\n";
        }
        else cout<<"no\n";
    }
    return 0;
}
