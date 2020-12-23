//LOWEST COMMON ANCESTOR OF TWO NODES IN A BINARY TREE

#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int val;
    node* left;
    node* right;
    node(int d){
        val = d;
        left = right = NULL;
    }
};

node* lca(node* root, node* p, node* q) {
        //works fine when either both nodes exist in the tree, or both nodes donot exist
        //incorrect when one node is present but other is not
        if(root==NULL){
            return NULL;
        }
        if(root==p || root==q){
            return root;
        }
        auto left = lca(root->left, p, q);
        auto right = lca(root->right, p, q);
        
        if(left && right){
            return root;
        }
        if(left) return left;
        return right;
}

class custom{
    public:
    bool hasp, hasq;
    node* lca;
    custom(){
        hasp = hasq = false;
        lca = NULL;
    }
};

custom* helper(node* root, int p, int q) {
    //correct for all cases
    //base case
    if(root==NULL){
        return NULL;
    }
        
    //recursive case
    custom* ans = new custom();
        
    custom* left = helper(root->left, p, q);
    custom* right = helper(root->right, p, q);
        
    if(left && right){
        ans->hasp = true;
        ans->hasq = true;
        ans->lca = root;
        return ans;
    }
        
    if(left && (root->val==p || root->val==q)){
        ans->hasp = true;
        ans->hasq = true;
        ans->lca = root;
        return ans;
    }
        
    if(right && (root->val==p || root->val==q)){
        ans->hasp = true;
        ans->hasq = true;
        ans->lca = root;
        return ans;
    }
        
    if(left){
        return left;
    }
        
    if(right){
        return right;
    }
       
    if(root->val==p){
        ans->hasp = true;
        ans->hasq = false;
        ans->lca = NULL;
        return ans;
    }
    if(root->val==q){
        ans->hasq = true;
        ans->hasp = false;
        ans->lca = NULL;
        return ans;
    }
    return NULL;
}
    
node* lowestCommonAncestor(node* root, int p, int q) {
    custom *ans = helper(root, p, q);
    if(ans==NULL){
        return NULL;
    }
    return ans->lca;
}

//fn to build from level order
node* build(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    queue <node*> q;
    node* root = new node(d);
    q.push(root);

    while(!q.empty()){
        node* f = q.front();
        q.pop();
        int l; cin>>l;
        if(l!=-1){
            f->left = new node(l);
            q.push(f->left);
        }
        int r; cin>>r;
        if(r!=-1){
            f->right = new node(r);
            q.push(f->right);
        }
    }

    return root;
}
int main() {
    node* root = build();
    int a, b;
    cin>>a>>b;
    node* lca = lowestCommonAncestor(root, a, b);
    if(lca) cout<<lca->val;
    else cout<<"LCA does not exist.";
    return 0;
}
