// maybe O(N)
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int digits(int n){
    int len=0;
    while(n){
        len++;
        n/=10;
    }
    return len;
}

int func(string s){
    int l = s.length();
    int end = min(l/2, 10);
    int fin_len = -1;

    for(int i=1; i<=end; i++){
        int flag = 0;
        int cur_no = stoi(s.substr(0, i));
        int dig = digits(cur_no);
        int it=0;
        int miss_val;
        while(it+dig <= l){
            int str_no = stoi(s.substr(it, dig));
            if(str_no==cur_no){
                it += dig;
                cur_no++;
                dig = digits(cur_no);
                continue;
            }
            else if(!flag){
                miss_val = cur_no;
                cur_no++;
                dig = digits(cur_no);
                flag = 1; // dont increase iterator
                continue;
            }
            else{
                flag++;
                break;
            }
        }
        if(flag!=2){
            return miss_val;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int cnt=1;
    while(t--){
        string s; 
        cin>>s;
        
       int ans = func(s);
       cout<<ans<<endl;
    }
    return 0;
}
