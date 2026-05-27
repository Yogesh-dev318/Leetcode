class Solution {
public:
    void combine(int i,vector<int> &arr,int target,vector<vector<int>> &ans,vector<int> &d){
        if(i==arr.size()){
            if(target==0){
                ans.push_back(d);
            }
            return;
        }
        if(arr[i]<=target){
            d.push_back(arr[i]);
            combine(i,arr,target-arr[i],ans,d);
            d.pop_back();
        }
        
        combine(i+1,arr,target,ans,d);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> d;
        combine(0,candidates,target,ans,d);
        return ans;
    }
};