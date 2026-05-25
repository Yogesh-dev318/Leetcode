class Solution {
public:
    void per(vector<int> &ds,map<int,int> &mp,vector<vector<int>> &ans,vector<int> &nums){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==1) continue;
            ds.push_back(nums[i]);
            mp[nums[i]]=1;
            per(ds,mp,ans,nums);
            mp[nums[i]]=0;
            ds.pop_back();
        }
    } 
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]=0;
        }
        per(ds,map,ans,nums);
        return ans;
    }
};