#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int no;
        cin>>no;
        int median = no;
        priority_queue <int> lt;
        priority_queue <int, vector<int>, greater<int> > rt;
        lt.push(median);
        n--;
        cout<<median<<" ";
        while(n--){
            cin>>no;
            if(no>median){
                rt.push(no);
            }
            else{
                lt.push(no);
            }
            if(lt.size()-rt.size()>1 or rt.size()-lt.size()>1){
                if(lt.size()>rt.size()){
                    while(lt.size()-rt.size()>1){
                        int top = lt.top();
                        lt.pop();
                        rt.push(top);
                    }
                }
                else{
                    while(rt.size()-lt.size()>1){
                        int top = rt.top();
                        rt.pop();
                        lt.push(top);
                    }
                }
            }
            if(lt.size()==rt.size()){
                median = (lt.top()+rt.top())/2;
            }
            else if(lt.size()>rt.size()){
                median = lt.top();
            }
            else{
                median = rt.top();
            }
            cout<<median<<" ";
        }
        cout<<endl;
    }
    return 0;
}
