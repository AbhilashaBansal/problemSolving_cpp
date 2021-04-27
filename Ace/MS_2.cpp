// HEAPS

// O(nlogn)

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
        int n; cin>>n;
        int x; cin>>x;
        int median = x; 

        priority_queue <int> max_heap; // left heap
        priority_queue<int, vector<int>, greater<int>> min_heap; // right heap
       
        max_heap.push(x);
        cout<<median<<" ";

        for(int i=1; i<n; i++){
            cin>>x;
            if(x>median) min_heap.push(x);
            else max_heap.push(x);

            if(max_heap.size()>min_heap.size()){
                while(max_heap.size()-min_heap.size()>1){
                    int ele = max_heap.top();
                    max_heap.pop();
                    min_heap.push(ele);
                }
            }
            else if(min_heap.size()>max_heap.size()){
                while((min_heap.size()-max_heap.size())>1){
                    int ele = min_heap.top();
                    min_heap.pop();
                    max_heap.push(ele);
                }
            }

            if(min_heap.size()>max_heap.size()) median = min_heap.top(); // constant work
            else if(max_heap.size()>min_heap.size()) median = max_heap.top();
            else median = (min_heap.top()+max_heap.top())/2;

            cout<<median<<" ";
        }
        cout<<endl;
    }
    return 0;
}
