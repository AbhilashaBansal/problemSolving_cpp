class Solution {
public:
    pair <int, int> helper(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        
        pair <int,int> left = helper(root->left);
        pair <int,int> right = helper(root->right);
        
        //option 1 rob this house (can't rob left and right)
        int ans1 = root->val + left.second + right.second;
        
        //option 2 dont rob this house
        int ans2 = left.first + right.first;
        ans2 = max(ans2, left.first+right.second);
        ans2 = max(ans2, left.second+right.first);
        ans2 = max(ans2, left.second+right.second);
        return {ans1, ans2};
    }
    
    int rob(TreeNode* root) {
        auto ans = helper(root);
        return max(ans.first, ans.second);
    }
};
