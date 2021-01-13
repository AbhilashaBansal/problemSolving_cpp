class Solution {
public:
    
    int solve(string &s, int st, int e, int dp[][1001]){
        if(st>e) return dp[st][e]=0;
        if(st==e) return dp[st][e]=1;
        
        if(dp[st][e]!=-1) return dp[st][e];
        
        if(s[st]==s[e]) return dp[st][e] = solve(s, st+1, e-1, dp)+2;
        else return dp[st][e] = max(solve(s, st+1, e, dp), solve(s, st, e-1, dp));
    }
    
    int longestPalindromeSubseq(string s) {
        int dp[1001][1001];
        memset(dp, -1, sizeof dp);
        return solve(s, 0, s.length()-1, dp);
    }
};
