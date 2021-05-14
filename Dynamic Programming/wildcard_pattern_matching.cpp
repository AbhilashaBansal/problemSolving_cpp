#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// WILDCARD PATTERN MATCHING
// O(N^2) 2D-DP Solution

// '?' matches one character
// '*' matches zero or more characters of any kind (any sequence)

int utils(int i, string text, int j, string pattern, vector<vector<int>> &dp){
    // base cases
	if(i==text.length() && j==pattern.length()){
        return 1;
    }    
    if(j>=pattern.length()) return 0;
    if(i>=text.length()) {
        while(j<pattern.length()){
            if(pattern[j++]!='*') return 0;
        }
        return 1;
    }
    
    if(dp[j][i] != -1) return dp[j][i];
	
    if(pattern[j]==text[i] || pattern[j]=='?'){
        // match single char of both
        return dp[j][i] = utils(i+1, text, j+1, pattern, dp);
    }

    if(pattern[j]=='*'){
        // * matches 0 chars
        dp[j][i] = utils(i, text, j+1, pattern, dp);

        // * matches 1 char (not needed, will be covered in 0 char case of next fn call)
        // dp[j][i] = dp[j][i] || utils(i+1, text, j+1, pattern, dp); 

        // * matches this and potentially other chars present ahead
        dp[j][i] = dp[j][i] || utils(i+1, text, j, pattern, dp); 

        return dp[j][i];
    }
    
    // no possibility of match left
    return dp[j][i]=0;
}

bool wildcardMatching(string pattern, string text){
    int n = text.length(), m = pattern.length();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    
    int ans = utils(0, text, 0, pattern, dp);
    return (ans==1?true:false);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, pat;
    cin>>s>>pat;
    cout<<wildcardMatching(pat, s);
    return 0;
}
