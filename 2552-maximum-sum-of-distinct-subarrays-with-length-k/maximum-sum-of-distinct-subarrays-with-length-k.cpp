class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int> st;
        long long maxsum=0;
        int l=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            while(st.find(nums[i])!=st.end()){
                st.erase(nums[l]);
                sum-=nums[l];
                l++;
            }
            st.insert(nums[i]);
            sum+=nums[i];
            if (i-l+1>k) {
                st.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            if (i-l+1==k) {
                maxsum = max(maxsum, sum);
            }
        }
        return maxsum;
    }
};