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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> ans1;
        queue<TreeNode*> q;
        if(root==NULL) return ans1;
        q.push(root);
        while(!q.empty()){
            vector<int> ds;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                ds.push_back(temp->val);
            }
            ans.push_back(ds);
        }
        int n=ans.size();
        for(int i=0;i<n;i++){
            ans1.push_back(ans[i].back());
        }
        return ans1;
    }
};