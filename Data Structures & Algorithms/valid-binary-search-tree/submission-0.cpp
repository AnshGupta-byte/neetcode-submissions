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
    bool isBst(TreeNode* root, long long l, long long r) {
        if (!root) return true;
        if (root->val <= l || root->val >= r) return false;
        bool x = true, y = true;
        if (l <= root->val && r >= root->val) {
            x = isBst(root->left, l, root->val);
            y = isBst(root->right, root->val, r);
        }
        return x && y;
    }
    bool isValidBST(TreeNode* root) { return isBst(root, LLONG_MIN, LLONG_MAX); }
};
