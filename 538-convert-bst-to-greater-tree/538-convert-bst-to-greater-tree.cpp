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
    int curr_sum;
    void traverse(TreeNode* node)
    {
        if(node->right) traverse(node->right);
        
        curr_sum += node->val;
        node->val = curr_sum;
        
        if(node->left) traverse(node->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        
        curr_sum = 0;
        traverse(root);
        return root;
    }
};