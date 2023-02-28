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
    string inorder(TreeNode* node, unordered_map<string, vector<TreeNode*>> &m) {
        if (node == NULL)
            return "";
            
        string s = "(" + inorder(node->left, m) + to_string(node->val) + inorder(node->right, m) + ")";

        m[s].push_back(node);

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> m;

        inorder(root, m);

        vector<TreeNode*> answer;

        for (auto &pair: m) {
            if (pair.second.size() <= 1)
                continue;

            answer.push_back(pair.second[0]);
        }

        return answer;
    }
};