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
private: 
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last; 
public:
    // void inorder(TreeNode* root,vector<int>& arr){
    //     if(root==NULL){
    //         return;
    //     }
    //     inorder(root->left,arr);
    //     arr.push_back(root->val);
    //     inorder(root->right,arr);
    // }
    // void setnodes(TreeNode* root,vector<int> arr,int& i){
    //     if(root==NULL){
    //         return;
    //     }
    //     if(i==arr.size()){return;}
    //     setnodes(root->left,arr,i);
    //     root->val = arr[i];
    //     i++;
    //     setnodes(root->right,arr,i);
    // }
    void inorder(TreeNode* root) {
        if(root == NULL) return; 
        inorder(root->left);
        if (prev != NULL && (root->val < prev->val))
        {
            if ( first == NULL )
            {
                first = prev;
                middle = root;
            }
            else
                last = root;
        }
        prev = root;
        inorder(root->right); 
    }
    void recoverTree(TreeNode* root) {
        // vector<int> arr;
        // inorder(root,arr);
        // sort(arr.begin(),arr.end());
        // int i=0;
        // setnodes(root,arr,i);
        first = middle = last = NULL; 
        prev = new TreeNode(INT_MIN); 
        inorder(root);
        if(first && last) swap(first->val, last->val); 
        else if(first && middle) swap(first->val, middle->val);
    }
};