class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum==k){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;

        unordered_map<int ,int> mpp;
        mpp[0]=1;
        int preSum=0;
        int count=0;
        for(int i=0;i<n;i++){
            preSum+=nums[i];
            int remove=preSum-k;
            count+=mpp[remove];
            mpp[preSum]+=1;
        }
        return count;
    }
};