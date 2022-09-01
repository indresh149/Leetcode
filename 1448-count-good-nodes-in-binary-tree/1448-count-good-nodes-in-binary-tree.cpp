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
    void countgoodnodes(TreeNode *root, int &cnt,int maxforthisstep)
    {
        if(root == NULL) return;
        if(root->val >= maxforthisstep)
        {
            cnt++;
            maxforthisstep = root->val;
        }
        countgoodnodes(root->left,cnt,maxforthisstep);
         countgoodnodes(root->right,cnt,maxforthisstep);
        
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        if(root == NULL) return cnt;
        countgoodnodes(root,cnt,root->val);
        return cnt;
    }
};