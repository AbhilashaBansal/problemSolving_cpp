// MAXIMUM XOR SUBARRAY

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class node {
    public:
    node* left;
    node* right;

    node(){
        left = right = NULL;
    }
};

class Trie {
    public: 
    node* root;

    Trie(){
        root = new node();
    }

    void insert(int val){
        node* temp = root;

        for(int i=31; i>=0; i--){
            int bit = (val>>i)&1;
            if(bit==0){
                if(temp->left==NULL) temp->left = new node();
                temp = temp->left;
            }
            else{
                // bit is one
                if(temp->right==NULL) temp->right = new node();
                temp = temp->right;
            }
        }
    }

    int max_xor_helper(int val){
        int ans = 0; 
        node* temp = root;

        for(int i=31; i>=0; i--){
            int bit = (val>>i)&1;
            if(bit==0){
                if(temp->right!=NULL){
                    ans += (1<<i);
                    temp = temp->right;
                }
                else{
                    temp = temp->left;
                }
            }

            else{
                // bit is 1, we need to find 0
                if(temp->left!=NULL){
                    ans += (1<<i);
                    temp = temp->left;
                }
                else{
                    temp = temp->right;
                }
            }
        }

        return ans;
    }

};

int max_xor(int a[], int n){
    Trie t;
    int ans = 0;

    for(int i=0; i<n; i++){
        t.insert(a[i]);
        ans = max(ans, t.max_xor_helper(a[i]));
    }

    return ans;
}

int main() {
    int n;
    cin>>n;
    int a[100005];

    for(int i=0; i<n; i++){
        cin>>a[i];
        if(i==0) continue;
        a[i] = a[i]^a[i-1]; // maintaining cumulative xor
    }

    int ans = max_xor(a, n);
    cout<<ans<<endl;
    return 0;
}
