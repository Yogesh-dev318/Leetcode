class Solution {
public:
    void subsetsum(int index,vector<int> &nums,vector<int> &ds,set<vector<int>> &st,int n){
        if(index==n){
            st.insert(ds);
            return;
        }
        ds.push_back(nums[index]);
        subsetsum(index+1,nums,ds,st,n);
        ds.pop_back();
        subsetsum(index+1,nums,ds,st,n);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ds;
        set<vector<int>> st;
        subsetsum(0,nums,ds,st,n);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};