class Solution {
public:
    void combine(int ind,vector<int> &arr,int target,vector<vector<int>> &ans,vector<int> &d){
        if(ind==arr.size()){
            if(target==0){
                ans.push_back(d);
            }
            return;
        }
        if(target==0){
            ans.push_back(d);
            return;
        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]){
                continue;
            }
            if (arr[i] > target) {
                break;
            }
            else{
                if(arr[i]<=target){
                d.push_back(arr[i]);
                combine(i+1,arr,target-arr[i],ans,d);
                d.pop_back();
            }
        }
        }
        // combine(i+1,arr,target,ans,d);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> d;
        vector<vector<int>> ans;
        combine(0,candidates,target,ans,d);
        return ans;
    }
};