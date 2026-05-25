class Solution {
public:
    // void per(vector<int> &ds,map<int,int> &mp,vector<vector<int>> &ans,vector<int> &nums){
    //     if(ds.size()==nums.size()){
    //         ans.push_back(ds);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         if(mp[nums[i]]==1) continue;
    //         ds.push_back(nums[i]);
    //         mp[nums[i]]=1;
    //         per(ds,mp,ans,nums);
    //         mp[nums[i]]=0;
    //         ds.pop_back();
    //     }
    // } 
    void per(int index,vector<int>& nums,vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            per(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<vector<int>> ans;
        // vector<int> ds;
        // map<int,int> map;
        // for(int i=0;i<nums.size();i++){
        //     map[nums[i]]=0;
        // }
        // per(ds,map,ans,nums);
        // return ans;
        vector<vector<int>> ans;
        per(0,nums,ans);
        return ans;
    }
};