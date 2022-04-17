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
    TreeNode* increasingBSTT(TreeNode* root, TreeNode* tail = NULL) {
        if (!root) return tail;
        TreeNode* res = increasingBSTT(root->left, root);
        root->left = NULL;
        root->right = increasingBSTT(root->right, tail);
        return res;
    }
    TreeNode* increasingBST(TreeNode* root) {
        return increasingBSTT(root, NULL);
    }
};