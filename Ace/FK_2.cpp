// STRING IMPLEMENTATION O(N)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        string s, s2;
        cin>>s;
        for(int i=0; i<s.length(); i++){
            if((s[i]-'0')%2==0){
                //even
                s[i] = 'I';
            }
            else{
                //odd
                s[i] = 'D';
            }
        }
        // cout<<s<<endl;

        // pre computation
        vector <string> v;
        char cur_seq = s[0];
        int len=1;
        for(int i=1; i<s.length(); i++){
            if(s[i]==s[i-1]){
                len++;
            }
            else{
                v.push_back(cur_seq + to_string(len));
                len = 1;
                cur_seq = s[i];
            }
        }
        if(len){
            v.push_back(cur_seq + to_string(len));
        }

        int max_no_till_now = 0;
        int i=0; 
        //setting the first character, acc to I or D
        if(v[0][0]=='I'){
            s2="1";
            max_no_till_now=1;
        }
        else{
            int num = v[0][1]-'0' + 1;
            s2 = num+'0';
            max_no_till_now = num;
        }

        while(i<v.size()){
            string ele = v[i];
            char seq = ele[0]; // I or D
            int nm = ele[1]-'0'; // number of consec I or D
            if(seq=='D'){
                int no = s2[s2.size()-1] - '0'; // last char of string, jo humne already set kiya hua hai for a dec seq
                no--;
                while(nm--){
                    s2 += (no+'0');
                    no--;
                }
            }
            else{
                // I 
                int nm2 = nm-1;
                while(nm2--){
                    s2 += (++max_no_till_now + '0'); // mast
                }
                if(i+1<v.size()){
                    // another dec seq to follow
                    int next_nm = v[i+1][1]-'0'; // no of consec Ds in next turn
                    int tmp = max_no_till_now + 1 + next_nm;
                    s2 += (tmp + '0');
                    max_no_till_now = tmp;
                }
                else{
                    s2 += (++max_no_till_now + '0');
                }
            }
            i++;
        }
        cout<<s2<<endl;
    }
    return 0;
}
