class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        int lcs=1;
        int lastsmaller=INT_MIN;
        if(n==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(lastsmaller+1==nums[i]){
                lastsmaller=nums[i];
                count++;
            }
            else if(lastsmaller!=nums[i]){
                lastsmaller=nums[i];
                count=1;
            }
            lcs=max(lcs,count);
        }
        return lcs;
    }
};