#include <iostream>
using namespace std;

int solve(string &s, int st, int e, int dp[][100]){
    if(st>e) return dp[st][e]=0;
    if(st==e) return dp[st][e]=1;

    if(dp[st][e]!=-1) return dp[st][e];

    if(s[st]==s[e]) return dp[st][e] = solve(s, st+1, e-1, dp)+2;
    else return dp[st][e] = max(solve(s, st+1, e, dp), solve(s, st, e-1, dp));
}
    
string solve(string &s, int st, int e, string dp[][100]){
    if(st>e) return dp[st][e]="";
    if(st==e) return dp[st][e]=s.substr(st,1);

    if(dp[st][e]!="-1") return dp[st][e];

    if(s[st]==s[e]) return dp[st][e] = s[st]+solve(s, st+1, e-1, dp)+s[e];
    else{
        string a=solve(s, st+1, e, dp); //cout<<a<<" ";
        string b=solve(s, st, e-1, dp); //cout<<b<<" ";
        if(a.length()>=b.length()){
            return dp[st][e]=a;
        }
        return dp[st][e]=b;
    } 
}

int main() {
    string s;
    cin>>s;

    int dp[100][100];
    memset(dp, -1, sizeof dp);
    cout<<solve(s, 0, s.length()-1, dp)<<" ";

    string dps[100][100];
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            dps[i][j]="-1";
        }
    }
    cout<<solve(s, 0, s.length()-1, dps);
    return 0;
}
