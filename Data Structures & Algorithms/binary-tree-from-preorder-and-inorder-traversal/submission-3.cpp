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
    unordered_map<int, int> mp;
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is,
                        int ie) {
        if (ps > pe) return nullptr;
        TreeNode* temp = new TreeNode(preorder[ps]);
        int idx = mp[preorder[ps]];
        int x = idx - is;
        temp->left = construct(preorder, inorder, ps + 1, ps + x, is, idx - 1);
        temp->right = construct(preorder, inorder, ps + 1 + x, pe, idx + 1, ie);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return construct(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
