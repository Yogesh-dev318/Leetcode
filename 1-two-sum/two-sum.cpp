class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        // vector<int> ans;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]+nums[j]==target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;

        map<int,int> map;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int tar=target-nums[i];
            if(map.find(tar)!=map.end()){
                ans.push_back(i);
                ans.push_back(map[tar]);
            }
            map[nums[i]]=i;
        }
        return ans;

    }
};