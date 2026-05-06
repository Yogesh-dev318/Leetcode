class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                maxi++;
                ans=max(ans,maxi);
            }
            else if(nums[i]==0){
                maxi=0;
            }
        }
        return ans;
    }
};