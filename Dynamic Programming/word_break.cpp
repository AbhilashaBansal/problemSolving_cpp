// WORD BREAK 1
// O(N^2)
// We have to fill a dp array of size N, and to fill each entry, we must iterate over dp table from i+1 .... N
// Hence, Time Complexity will be O(N^2)

#include <bits/stdc++.h>
using namespace std;

unordered_map <string, bool> m;
int *dp;
    
int isPos(string s, int idx){
    if(idx==s.length()) return dp[idx]=1;
        
    if(dp[idx]!=-1) return dp[idx];
        
    for(int end=idx; end<s.length(); end++){
        string str = s.substr(idx, end-idx+1);
        if(m.count(str) && isPos(s, end+1)==1) return dp[idx]=1;
    }
        
    return dp[idx]=0;
}
    
bool wordBreak(string s, string wordDict[], int n) {
        
    //creating the dictionary
    for(int i=0; i<n; i++){
        m[wordDict[i]]=true;
    }
    
    dp = new int[s.length()+1];
    for(int i=0; i<=s.length(); i++){
        dp[i] = -1;
    }
        
    return isPos(s, 0);
}

int main() {
    string dict[]={"john", "on", "code", "music", "mayer", "wall", "street", "workin"};
    cout<<wordBreak("johnmayerondrums", dict, 8)<<endl;
    cout<<wordBreak("workinonwallstreet", dict, 8)<<endl;
    return 0;
}
