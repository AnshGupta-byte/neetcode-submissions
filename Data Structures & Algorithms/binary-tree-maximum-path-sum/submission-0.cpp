/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
int ans =INT_MIN;
int maxsum(TreeNode* root){
    if(!root) return 0;

    int l = maxsum(root->left);
    int r = maxsum(root->right);

    ans = max(ans, root->val + max(l,0) + max(r,0));
    return root->val + max({l,r,0});
}
    int maxPathSum(TreeNode* root) {
        maxsum(root);
        return ans;
    }
};
