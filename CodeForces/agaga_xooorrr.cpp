// interesting question based on partitioning & cumulative xor

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
        int* a=new int[n];
        int* cxor = new int[n];
        cin>>a[0];
        cxor[0] = a[0];
        for(int i=1; i<n; i++) {
            cin>>a[i];
            cxor[i] = cxor[i-1]^a[i];
        }
        bool flag = true;
        // op1 : 2 final values, in which case overall xor must be 0
        // op2: 3 final values, in which case xor of 3 partitions must be equal (O(n^2)) 
        for(int i=0; i<30; i++){
            int tmp_xor=0;
            for(int j=0; j<n; j++){
                int bit = (a[j]>>i)&1;
                tmp_xor = tmp_xor^bit;
            }
            // cout<<tmp_xor<<"-";
            if(tmp_xor!=0){
                flag = false;
                break;
            }
        }
        if(flag) cout<<"YES\n";
        else {
            // check for option 2
            for(int i=1; i<=n-2; i++){
                for(int j=i; j<=n-2; j++){
                    int part1 = cxor[i-1];
                    int part2 = cxor[j]^cxor[i-1];
                    int part3 = cxor[n-1]^cxor[j];
                    if(part1==part2 && part2==part3){
                        flag=true;
                        break;
                    }
                }
                if(flag==true) break;
            }
            if(flag) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
