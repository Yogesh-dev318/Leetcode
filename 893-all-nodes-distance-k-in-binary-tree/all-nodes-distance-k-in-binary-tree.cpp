/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     void subtreeNodes(TreeNode* root, int k, vector<int>& ans) {
//         if (!root || k < 0) return;
//         if (k == 0) {
//             ans.push_back(root->val);
//             return;
//         }
//         subtreeNodes(root->left, k - 1, ans);
//         subtreeNodes(root->right, k - 1, ans);
//     }
//     int solve(TreeNode* root, TreeNode* target, int k,vector<int>& ans) {
//         if (!root) return -1;
//         if (root == target) {
//             subtreeNodes(root, k, ans);
//             return 0;
//         }
//         int leftDist = solve(root->left, target, k, ans);
//         if (leftDist != -1) {
//             if (leftDist + 1 == k)
//                 ans.push_back(root->val);
//             else
//                 subtreeNodes(root->right,k - leftDist - 2,ans);
//             return leftDist + 1;
//         }
//         int rightDist = solve(root->right, target, k, ans);
//         if (rightDist != -1) {
//             if (rightDist + 1 == k)
//                 ans.push_back(root->val);
//             else
//                 subtreeNodes(root->left,k - rightDist - 2,ans);
//             return rightDist + 1;
//         }
//         return -1;
//     }
//     vector<int> distanceK(TreeNode* root,TreeNode* target,int k) {
//         vector<int> ans;
//         solve(root, target, k, ans);
//         return ans;
//     }
// };

class Solution {
public:
    void markParents(TreeNode* root,map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root,TreeNode* target,int k) {
        map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);
        map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int currLevel = 0;
        while(!q.empty()) {
            int size = q.size();
            if (currLevel == k)
                break;
            currLevel++;
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    vis[curr->left] = true;
                    q.push(curr->left);
                }
                if(curr->right && !vis[curr->right]){
                    vis[curr->right] = true;
                    q.push(curr->right);
                }
                if(parent.find(curr)!=parent.end() && !vis[parent[curr]]) {
                    vis[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};