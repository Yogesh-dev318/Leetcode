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
    void subtreeNodes(TreeNode* root, int k, vector<int>& ans) {
        if (!root || k < 0) return;
        if (k == 0) {
            ans.push_back(root->val);
            return;
        }
        subtreeNodes(root->left, k - 1, ans);
        subtreeNodes(root->right, k - 1, ans);
    }
    int solve(TreeNode* root, TreeNode* target, int k,vector<int>& ans) {
        if (!root) return -1;
        if (root == target) {
            subtreeNodes(root, k, ans);
            return 0;
        }
        int leftDist = solve(root->left, target, k, ans);
        if (leftDist != -1) {
            if (leftDist + 1 == k)
                ans.push_back(root->val);
            else
                subtreeNodes(root->right,k - leftDist - 2,ans);
            return leftDist + 1;
        }
        int rightDist = solve(root->right, target, k, ans);
        if (rightDist != -1) {
            if (rightDist + 1 == k)
                ans.push_back(root->val);
            else
                subtreeNodes(root->left,k - rightDist - 2,ans);
            return rightDist + 1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root,TreeNode* target,int k) {
        vector<int> ans;
        solve(root, target, k, ans);
        return ans;
    }
};