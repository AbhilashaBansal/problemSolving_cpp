// interesting question based on SUBSET PARTITIONING 

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool comp(int a, int b){
    return a>b;
}

bool isSubsetSum(int arr[], int n, int sum)
{
    bool part[sum+ 1][n + 1];
    int i, j;
    // initialize top row as true
    for (i = 0; i <= n; i++)
        part[0][i] = true;
 
    // initialize leftmost column,
    // except part[0][0], as 0
    for (i = 1; i <= sum; i++)
        part[i][0] = false;
 
    // Fill the partition table in bottom up manner
    for (i = 1; i <= sum; i++) {
        for (j = 1; j <= n; j++) {
            part[i][j] = part[i][j - 1];
            if (i >= arr[j - 1])
                part[i][j] = part[i][j]
                             || part[i - arr[j - 1]][j - 1];
        }
    }
 
    return part[sum][n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // cin>>t;
    t=1;
    int cnt=1;
    while(t--){
        int n;
        cin>>n;
        int *a = new int[n];
        ll sm=0;
        bool odd=false;
        int odd_idx=-1;
        for(int i=0; i<n; i++){
            cin>>a[i];
            sm+=a[i];
            if(a[i]%2) {
                odd=true;
                odd_idx = i;
            }
        }

        if(sm%2==1){
            cout<<0;
            continue;
        }
        if(isSubsetSum(a, n, sm/2)==false){
            cout<<0;
            continue;
        }
        if(odd){
            cout<<1<<endl;
            cout<<odd_idx+1; continue;
        }
        else{
            int min_left_Set_bit = 31;
            int idx=-1;
            for(int i=0; i<n; i++){
                int tmp = __builtin_ctz(a[i]);
                if(tmp<=min_left_Set_bit){
                    min_left_Set_bit = tmp;
                    idx = i;
                }
            }
            cout<<1<<endl;
            cout<<idx+1<<endl;
        }
    }
    return 0;
}
