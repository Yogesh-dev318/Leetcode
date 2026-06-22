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
    void path(TreeNode* root,TreeNode* n,vector<TreeNode*>& ds,vector<TreeNode*>& arr){
        if(root==NULL){
            return;
        }
        ds.push_back(root);
        if(root==n){
            arr=ds;
            return;
        }
        path(root->left,n,ds,arr);
        path(root->right,n,ds,arr);
        ds.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr1;
        vector<TreeNode*> arr2;
        vector<TreeNode*> ds1,ds2;
        path(root,p,ds1,arr1);
        path(root,q,ds2,arr2);
        TreeNode* ans=NULL;
        for(int i=0;i<min(arr1.size(),arr2.size());i++){
            if(arr1[i]!=arr2[i]){
                break;
            }
            else{
                ans=arr1[i];
            }
        }
        return ans;
    }
};