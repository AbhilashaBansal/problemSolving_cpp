#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define piii pair <int, pair<int,int>>

// 725 DIV 3, Problem D
// Idea:
// need to find sum of exponents of prime factors, factors will be found till sqrt(max_no), O(sqrt(10^9))
// only prime factors are to be considered, hence form the prime sieve till sqrt(max_no)

int mx = 1000000005;
vector<int> primes;

void sieve(){
    int sz = sqrt(mx);
    vector <bool> v(sz, 1);
    v[0] = v[1] = false;
    for(int i=4; i<sz; i+=2){
        v[i] = false;
    }
    for(int i=3; i*i<sz; i+=2){
        if(v[i]){
            for(int j=i*i; j<sz; j+=i){
                v[j] = false;
            }
        }
    }

    for(int i=0; i<sz; i++){
        if(v[i]) primes.push_back(i);
    }
}

// for each number, iterate over all primes smaller than sqrt, to find sum of exponents
// prime numbers smaller than sqrt(10^9) ~ 3500
// henceO(3500)
int sum_of_prime_expo(int a){
    int ans=0;
    for(int p: primes){
        while(a%p==0){
            ans++;
            a /= p;
        }
    }
    if(a>1) ans++;
    return ans;
}

// overall complexity comes around ~ O(sqrt(N) + t*3500)
// t = 10^4
// time: O(sqrt(N) + 3.5 * 10^7)
// time: O(3*10^4 + 3.5 * 10^7)

// logical if else statements
bool check(int a, int b, int k){
    if(b<a) swap(a, b);

    // min is: 0 for a==b, 1 __gcd(a,b)==a(or b), 2 otherwise
    // max is always sum of as and bs
    // handle spl case: a==b, k==1, not poss !! 
    if(a==b && k==1) return false;
    if(__gcd(a, b)==a && k<1) return false;
    if(a!=b && __gcd(a,b)!=a && k<2) return false;

    int as = sum_of_prime_expo(a);
    int bs = sum_of_prime_expo(b);
    int tot = as+bs;
    if(k<=tot) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // need to find sum of exponents of prime factors
    // construct sieve upto sqrt of max number
    sieve();

    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        int a, b, k;
        cin>>a>>b>>k;

        if(check(a, b, k)) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}
