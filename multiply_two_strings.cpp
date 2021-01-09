#include <bits/stdc++.h>
using namespace std;

string multiply_two_strings(string a, string b){
    int m = a.length(), n = b.length();

    bool isNeg = false;
    if(a[0]=='-' && b[0]=='-'){
        a=a.substr(1);
        b=b.substr(1);
        m--, n--;
    }
    else if(a[0]=='-'){
        a=a.substr(1);
        m--;
        isNeg = true;
    }
    else if(b[0]=='-'){
        b=b.substr(1);
        n--;
        isNeg = true;
    }

    int *ans = new int[m+n]{0};

    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            int no = (a[i]-'0')*(b[j]-'0') + ans[i+j+1];
            ans[i+j+1] = no%10;
            ans[i+j] += no/10;
        }
    }

    string res="";
    for(int i=0; i<m+n; i++){
        if(res.length()!=0 || ans[i]!=0){
            res += ans[i]+'0';
        }
    }

    if(res=="") return "0";
    if(isNeg) res = '-' + res;
    return res;
}

int main() {

    //multiplication of two strings 
    string a, b;
    cin>>a>>b;
    cout<<multiply_two_strings(a, b)<<endl;    
    return 0;
}
