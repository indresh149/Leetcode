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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum=INT_MIN;
        int ans =-1,lev=0;
        while(q.size())
        {
            int n=q.size();
            int i =0,curr=0;
            while(i<n && q.size())
            {
                TreeNode* temp = q.front();
                q.pop();
                    if(temp->left)
                    q.push(temp->left);
                    if(temp->right)
                    q.push(temp->right);
                    curr+=temp->val;
                i++;
            }
            cout<<curr<<endl;
             lev++;
            if(curr>sum){ans=lev;sum=curr;}
           
        }
        return ans;
    }
};
