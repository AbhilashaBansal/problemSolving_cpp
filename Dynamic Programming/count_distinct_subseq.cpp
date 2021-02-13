#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

int previous[256];

int count_subseq(string a){
	for(int i=0;i<256;i++){
		previous[i]=-1;
	}

	ll dp[1005];
	dp[0]=1;

	for(int i=1; i<=a.length(); i++) {
		dp[i] = (dp[i-1]*2)%MOD;

		if(previous[a[i-1]]!=-1){
			int ind = previous[a[i-1]];

			dp[i] = dp[i] - dp[ind] + MOD;
			dp[i] %= MOD;
		}

		previous[a[i-1]] = i-1;
	}

	// for(int i=0; i<=a.length(); i++){
	// 	cout<<dp[i]<<" ";
	// }
	// cout<<endl;
	return dp[a.length()];
}

int main() {
	int t;
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		cout<<count_subseq(a)<<endl;
	}
	return 0;
}
