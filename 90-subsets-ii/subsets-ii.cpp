class Solution {
public:
    // void subsetsum(int index,vector<int> &nums,vector<int> &ds,set<vector<int>> &st,int n){
    //     if(index==n){
    //         st.insert(ds);
    //         return;
    //     }
    //     ds.push_back(nums[index]);
    //     subsetsum(index+1,nums,ds,st,n);
    //     ds.pop_back();
    //     subsetsum(index+1,nums,ds,st,n);
    // }
    void subsetsum(int index,vector<int> &nums,vector<int> &ds,vector<vector<int>> &ans){
        // if(index==nums.size()){
        //     return;
        // }
        ans.push_back(ds);
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            subsetsum(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // vector<int> ds;
        // set<vector<int>> st;
        // subsetsum(0,nums,ds,st,n);
        // vector<vector<int>> ans(st.begin(),st.end());
        // // sort(ans.begin(),ans.end());
        // return ans;
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        subsetsum(0,nums,ds,ans);
        return ans;
    }
};