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
    int dfs(TreeNode* node, int maxSoFar) {
        if(node==NULL) return 0;
        int count=0;
        if(node->val>=maxSoFar) count = 1;
        maxSoFar=max(maxSoFar, node->val);
        count+=dfs(node->left,maxSoFar);
        count+=dfs(node->right,maxSoFar);
        return count;
    }
    int goodNodes(TreeNode* root) {
        // int ans = 0;
        // inorder(root, root, ans);
        // return ans;
        return dfs(root,root->val);
    }
};