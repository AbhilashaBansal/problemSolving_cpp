#include<iostream>
using namespace std;

int main () {
	int n, a[100001];
	long long int lsum=0;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
		lsum+=a[i];
	}
	int max_op = 0, op=0;
	if(lsum%n==0){
		long long int load = lsum/n;
		for(int i=0; i<=n-1; i++){
			op += a[i] - load;
			max_op = max(max_op, abs(op));
		}
		cout<<max_op;
	}
	else{
		cout<<-1<<endl;
	}
	return 0;
}