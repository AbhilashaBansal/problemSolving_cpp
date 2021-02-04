#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[100001];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	unordered_map <int, int> mp;
	int e=0;
	long long int sum=0;
	for(int s=0; s<n; s++){
		while(e<=n-1 and mp.find(a[e])==mp.end()){
			mp[a[e]]=1;
			e++;
		}
		sum += ((e-s)*(e-s+1))/2;
        sum %= 1000000007;
		mp.erase(a[s]);
	}
	cout<<sum<<endl;
	return 0;
}