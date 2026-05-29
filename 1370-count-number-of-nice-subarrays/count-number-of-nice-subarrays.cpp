class Solution {
public:
    int fun(vector<int> &nums,int k){
        int l=0;
        int r=0;
        int cnt=0;
        int odd=0;
        while(r<nums.size()){
            if(nums[r]%2!=0){
                odd++;
            }
            while(odd>k){
                if(nums[l]&2!=0){
                    odd--;
                }
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=fun(nums,k)-fun(nums,k-1);
        return ans;
    }
};