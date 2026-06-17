/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getpath(TreeNode* root,vector<TreeNode*>& ans,vector<TreeNode*>& ds,TreeNode* n){
        if(root==NULL){
            return;
        }
        ds.push_back(root);
        if(root==n){
            ans=ds;
        }
        getpath(root->left,ans,ds,n);
        getpath(root->right,ans,ds,n);
        
        ds.pop_back();
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> node1,node2,ds;
        getpath(root,node1,ds,p);
        getpath(root,node2,ds,q);
        TreeNode* lca=NULL;
        int n=min(node1.size(),node2.size());
         for(int i = 0; i < n; i++) {
            if(node1[i] ==  node2[i])
                lca = node1[i];
            else
                break;
        }
        return lca;
    }
};