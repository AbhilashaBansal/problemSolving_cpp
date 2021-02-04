#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int n;
    cin>>n;

    vector <pair<int,int> > v(n);
    for(int i=0; i<n; i++){
        int d, f;
        cin>>d>>f;
        v[i] = {d,f};
    }

    int D, F;
    cin>>D>>F;
    for(int i=0; i<n; i++){
        v[i].first = D-v[i].first;
    }
    sort(v.begin(), v.end());

    priority_queue <int> pq;

    int prev_x = 0, st_no=0; 
    bool flag=false;
    int st_vis = 0;

    while(st_no<n){
        if(F >= v[st_no].first-prev_x){
            F -= v[st_no].first-prev_x;
            pq.push(v[st_no].second); // adding this fuel st as potential fuel st
            prev_x = v[st_no].first;
            st_no++;
        }
        else{
            if(pq.empty()){
                flag = true;
                break;
            }
            else{
                F += pq.top();
                pq.pop();
                st_vis++;
            }
        }
    }

    if(flag){
        cout<<-1<<endl;
    }
    else{
        D = D-v[n-1].first;
        if(F >= D){
            cout<<st_vis<<endl;
        }
        else{
            while(F<D){
                if(pq.empty()){
                    flag = true; break;
                }
                F+=pq.top();
                pq.pop();
                st_vis++;
            }
            if(flag) cout<<-1<<endl;
            else{
                cout<<st_vis<<endl;
            }
        }
    }

    return 0;
}
