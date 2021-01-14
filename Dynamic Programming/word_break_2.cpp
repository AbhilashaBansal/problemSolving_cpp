#include <bits/stdc++.h>
using namespace std;


unordered_map <string, vector<string> > dp;
    
vector<string> solve(string s, vector<string>& wordDict){
    vector <string> ans;
    //base case
    if(s.length()==0) return {""};

    //dp case
    if(dp.count(s)) return dp[s];
        
    //recursive case
    vector <string> chhotaAns;
    for(auto word: wordDict){
        if(s.substr(0, word.length())==word){
            chhotaAns = solve(s.substr(word.length()), wordDict);

            for(auto x: chhotaAns){
                string space = x.length()?" ":"";
                ans.push_back(word+space+x);
            }
        }
    }
        
    return dp[s]=ans;
}

int main() {
    string s="catsanddog";
    string v[] = {"cats", "dogs", "dog", "cat", "and", "sand", "sandog"};
    vector<string> v1;
    for(auto str: v){
        v1.push_back(str);
    }

    dp.clear();
    vector <string> ans = solve(s, v1);
    for(auto p: ans){
        cout<<p<<"\n";
    }
    return 0;
}
