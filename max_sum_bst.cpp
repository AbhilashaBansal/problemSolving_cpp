class Solution {
public:
    int maxs = 0;
    
    class custom{
        public:
        int minv, maxv;
        int sm;
        custom(){
            sm=0;
            minv = INT_MAX;
            maxv = INT_MIN;
        }
    };
    
    custom solve(TreeNode* root) {
        custom ans;
        if(root==NULL){
            return ans;
        }
        
        custom l = solve(root->left);
        custom r = solve(root->right);
        int sm = l.sm + r.sm + root->val;
        
        if(root->val>l.maxv and root->val<r.minv){
            //is bst
            maxs = max(maxs, sm);
            ans.minv = min(root->val, l.minv);
            ans.maxv = max(root->val, r.maxv);
            ans.sm = sm;
            return ans;
        }
        else{
            ans.minv = INT_MIN;
            ans.maxv = INT_MAX;
            return ans;
        }
    }
    
    int maxSumBST(TreeNode* root) {
        maxs = 0;
        custom ans = solve(root);
        return maxs;
    }
};
