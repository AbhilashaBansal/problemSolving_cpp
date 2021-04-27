// 2D-DP, STRINGS & SUBSEQUENCE
// TRICKY!!!

// O(NM)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// DP[i][j] = k, where s[k:j] is shortest substring such that it contains t[0:i] as a subsequence
string func(string a, string b){
    int m = a.length(), n = b.length();
    vector <vector<int> > dp(n, vector<int>(m, -1));

    for(int i=0; i<m; i++){
        if(a[i]==b[0]) dp[0][i] = i;
        else dp[0][i] = -1;
    }

    for(int i=1; i<n; i++){
        // fill dp matrix in row major form
        int k = -1;
        for(int j=0; j<m; j++){
            if(a[j] == b[i]) dp[i][j] = k;
            // update k w/ next possible better val of k
            if(dp[i-1][j]!=-1) k = dp[i-1][j];
        }
    }

    int len = INT_MAX;
    string ans = "";
    for(int i=0; i<m; i++){
        if(dp[n-1][i]!=-1 && (i-dp[n-1][i]+1)<len){
            int k = dp[n-1][i];
            len = i-dp[n-1][i]+1;
            ans = a.substr(k, len);
        } 
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin>>s>>t;

    string ans = func(s, t);
    cout<<ans<<endl;
    return 0;
}
