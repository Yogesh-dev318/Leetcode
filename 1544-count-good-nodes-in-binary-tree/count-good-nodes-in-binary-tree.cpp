class Solution {
public:
    // void check(TreeNode* root, TreeNode* target,vector<int>& arr, vector<int>& ds) {
    //     if(root==NULL) return;
    //     ds.push_back(root->val);
    //     if(root==target){
    //         arr = ds;
    //         ds.pop_back();
    //         return;
    //     }
    //     check(root->left, target, arr, ds);
    //     check(root->right, target, arr, ds);
    //     ds.pop_back();
    // }
    // bool cc(vector<int>& arr) {
    //     int last = arr.back();
    //     for (int i=0;i<arr.size()-1;i++){
    //         if(arr[i] > last) return false;
    //     }
    //     return true;
    // }
    // void inorder(TreeNode* originalRoot, TreeNode* curr, int& ans) {
    //     if (curr == NULL) return;
    //     vector<int> arr;
    //     vector<int> ds;
    //     check(originalRoot, curr, arr, ds);
    //     if(cc(arr))
    //         ans++;
    //     inorder(originalRoot, curr->left, ans);
    //     inorder(originalRoot, curr->right, ans);
    // }
    int count = 0;
    void dfs(TreeNode* node,int curMax) {
        if (!node) return;
        if (node->val >= curMax){
            count++;
            curMax = node->val;
        }
        dfs(node->left, curMax);
        dfs(node->right, curMax);
    }
    int goodNodes(TreeNode* root) {
        // int ans = 0;
        // inorder(root, root, ans);
        // return ans;
        dfs(root,root->val);
        return count;
    }
};