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
    int size(TreeNode* root) {
        if (!root) return 0;
        return 1 + size(root->left) + size(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
       
        int sizel = size(root->left);
        if (sizel == k - 1) {
            return root->val;
        } else if (sizel > k - 1) {
            return kthSmallest(root->left, k);
        } else {
            return kthSmallest(root->right, k - sizel - 1);
        }
    }
};
