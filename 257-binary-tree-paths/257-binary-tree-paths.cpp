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
    vector<string> binaryTreePaths(TreeNode* root) {
       if(!root)
           return {};
        
        vector<string> l = binaryTreePaths(root->left);
        vector<string> r = binaryTreePaths(root->right);
        vector<string> ans;
        string temp = to_string(root->val);
        for(auto &str: l)
        {
            ans.push_back(str);
        }
        for(auto &str: r)
        {
            ans.push_back(str);
        }
        if(ans.empty())
        {
            ans.push_back(temp);
        }
        else
        {
            for(auto &x: ans)
            {
                x = temp + "->" + x;
            }
        }
        return ans;
    }
};