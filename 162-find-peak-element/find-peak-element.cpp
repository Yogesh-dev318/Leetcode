class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0;
        int end=nums.size()-1;
        while(low<end){
            int mid=(low+end)/2;
            if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            else{
                end=mid;
            }
        }
        return low;
    }
};