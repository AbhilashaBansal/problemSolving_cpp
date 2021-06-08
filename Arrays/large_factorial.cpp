#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>

// Factorial of Large Numbers
// O(N log10(N!)) ~ O(N*NlogN)

// space: O(log(N!)) (max no of digits in factorial)

void multiply(int ans[], int no, int &sz){
        
    int carry = 0;
    for(int i=0; i<sz; i++){
        int cur = ans[i]*no + carry;
        ans[i] = cur%10;
        carry = cur/10;
    }
    
    while(carry){
        ans[sz++] = carry%10;
        carry /= 10;
    }
}
    
vector<int> factorial(int N){
    int ans[5000]={0};
    ans[0]=1;
    
    int sz=1;
    for(int i=2; i<=N; i++){
        multiply(ans, i, sz);
    }
    
    vector<int> res(ans, ans+sz);
    reverse(res.begin(), res.end());
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        int n;
        cin>>n;
        vector<int> f = factorial(n);
        for(int x: f){
            cout<<x;
        }
        cout<<endl;
    }

    return 0;
}
