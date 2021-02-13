#include <bits/stdc++.h>
using namespace std;

string dp[1005][1005];

// Longest Common Subsequence --> Top Down Approach

string lcs(string a, string b, int i, int j){
    if(i==a.length() || j==b.length()){
        return "";
    }

    if(dp[i][j]!="-1") {
        return dp[i][j];
    }

    if(a[i]==b[j]){
        dp[i][j] = a[i] + lcs(a, b, i+1, j+1);
    }
    else{
        string op1 = lcs(a, b, i, j+1);
        string op2 = lcs(a, b, i+1, j);
        if(op1.length()>op2.length()){
            dp[i][j] = op1;
        }
        else{
            dp[i][j] = op2;
        }
    }

    return dp[i][j];
}

int main() {
   string a, b;
   cin>>a>>b;

    for(int i=0; i<1005; i++){
        for(int j=0; j<1005; j++){
            dp[i][j] = "-1";
        }
    }
    cout<<lcs(a, b, 0, 0);
    
    return 0;
}
