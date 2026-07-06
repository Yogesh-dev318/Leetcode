class Solution {
public:
    int countSubarrays(vector<int>& nums, int maxSum) {
        int subarrays = 1;
        int currentSum = 0;
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                subarrays++;
                currentSum = num;
            } else {
                currentSum += num;
            }
        }

        return subarrays;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0;
        int high=0;
        for(int num:nums){
            low=max(num,low);
            high+=num;
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(countSubarrays(nums,mid)>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};