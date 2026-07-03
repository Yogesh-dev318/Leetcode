class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int r=0;
        int mini=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                 mini=min(mini,i-r+1);
                sum-=nums[r];
                r++;
            }
        }
        return mini==INT_MAX ? 0 : mini;
    }
};