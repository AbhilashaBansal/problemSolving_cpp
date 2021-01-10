#include <bits/stdc++.h>
using namespace std;

int main() {
    string str, pat;
    cin>>str>>pat;
    int n = str.length(), m = pat.length();
    int fs[256] = {0};
    int fp[256] = {0};

    //freq array for pattern
    for(int i=0; i<m; i++){
        fp[pat[i]]++;
    }

    int count=0; //variable for kaam ke chars jitne hain abhi window me
    int start=0; //present ya current window ka left ind
    int start_min = -1; //ab tak ki min len window (jo condn satisfy kare) ka left ind
    int min_len = INT_MAX;

    for(int i=0; i<n; i++){
        fs[str[i]]++;
        if(fs[str[i]] <= fp[str[i]]){
            count++; //pattern me iski relevance hai
        }

        if(count==m){
            // ek apt window mil gayi, now we can try to minimize len by shrinking it
            while(fs[str[start]] > fp[str[start]]){
                fs[str[start]]--;
                start++;
            }

            //iske aage shrink nahi kar sakte
            int len = i-start+1;
            if(len<min_len){
                start_min = start;
                min_len = len;
            }
        }
    }

    if(start_min==-1){
        cout<<"No such substring found!\n";
    }
    else{
        cout<<min_len<<endl;
        cout<<str.substr(start_min, min_len);
    }
    return 0;
}
