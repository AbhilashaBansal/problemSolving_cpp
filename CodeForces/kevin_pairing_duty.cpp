#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>
#define mod 998244353

// Kevin on Pairing Duty
// O(N logN)
const int sz = 1000005;
vector <int> no_of_fs(sz);

void make_sieve(){
    // fn to generate smallest prime factor for each number
    for(int i=1; i<sz; i++) {
        if(i%2==0) no_of_fs[i] = 2;
        else no_of_fs[i] = i;
    }

    for(int i=3; i*i<sz; i+=2){
        if(no_of_fs[i]==i){
            // this is a prime no
            for(int j=i*i; j<sz; j+=i){
                if(no_of_fs[j]==j) no_of_fs[j] = i;
            }
        }
    }    
}

void find_no(){
    // fn to find the total number of factors of all numbers till n 
    make_sieve();
    
    for(int i=2; i<sz; i++){
        int smllst = no_of_fs[i];
        int val = i;
        int cnt = 1;
        while(val%smllst==0){
            val /= smllst;
            cnt++;
        }

        no_of_fs[i] = cnt*(no_of_fs[val]);
        no_of_fs[i] %= mod;
    }

    // O(N logN)
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    find_no();
   
    int n;
    cin>>n;

    // rec rel: ans[i] = sum of ans[1]....ans[i-1] + no_of_factors[i]
    ll sm=0, cur;
    for(int i=1; i<=n; i++){
        cur = sm + no_of_fs[i];
        cur %= mod;
        sm += cur;
        sm %= mod;
    }
    cout<<cur<<endl;

    return 0;
}
