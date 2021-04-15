#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        string a;
        cin>>a;
        if(a[0]=='0' || a[n-1]=='0'){
            cout<<"NO\n";
            continue;
        }
        int zer=0;
        for(int i=0; i<n; i++){
            if(a[i]=='0') zer++;
        }
        if(zer%2){
            cout<<"NO\n";
            continue;
        }

        string x=a, y=a;
        x[0] = y[0] = '(';
        x[n-1] = y[n-1] = ')';
        int ctr=1;
        for(int i=1; i<=n-2; i++){
            if(a[i]=='0'){
                x[i] = (ctr==1)?'(':')';
                y[i] = (ctr==1)?')':'(';
                ctr = 1-ctr;
            }
        }
        // cout<<ctr<<" ";
        ctr=1;
        for(int i=1; i<=n-2; i++){
            if(a[i]=='1'){
                x[i] = (ctr==1)?'(':')';
                y[i] = x[i];
                ctr = 1-ctr;
            }
        }
        cout<<"YES\n"<<x<<endl<<y<<endl;
    }
    return 0;
}
