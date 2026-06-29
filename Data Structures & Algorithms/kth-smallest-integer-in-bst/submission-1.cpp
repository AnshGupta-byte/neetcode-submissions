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
   public: /*
     int size(TreeNode* root) {
         if (!root) return 0;
         return 1 + size(root->left) + size(root->right);
     }
     */
    int kthSmallest(TreeNode* root, int k) {
        /*
         int sizel = size(root->left);
         if (sizel == k - 1) {
             return root->val;
         } else if (sizel > k - 1) {
             return kthSmallest(root->left, k);
         } else {
             return kthSmallest(root->right, k - sizel - 1);
         }
         */

        // morris inorder traversal

        TreeNode* curr = root;
        int cnt = 0;
        int ans = -1;
        while (curr) {
            if (curr->left == nullptr) {
                cnt++;
                if (cnt == k) ans = curr->val;
                curr = curr->right;
            } else {
                TreeNode* predecessor = curr->left;
                while (predecessor->right && predecessor->right != curr) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = curr;
                    curr = curr->left;
                }

                else {
                    predecessor->right = nullptr;
                    cnt++;
                    if (cnt == k) ans = curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
