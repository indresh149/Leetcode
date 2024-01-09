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
    vector<int> v;
    void dfs(TreeNode *root){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right== NULL){
            v.push_back(root->val);
            return;
        }
        
        dfs(root->left);
        dfs(root->right);
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        v.clear();
        dfs(root1);
        vector<int> v1;
        
        v1 = v;
        
        v.clear();
        dfs(root2);
        
        if(v.size() != v1.size()) return 0;
        
        for(int i=0;i<v.size();i++){
            if(v[i]!= v1[i]) return 0;
        }
        
        return 1;
        
    }
};