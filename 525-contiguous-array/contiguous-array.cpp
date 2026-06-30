class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int presum=0;
        int len=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                presum=presum-1;
            }
            else{
                presum=presum+1;
            }
            if(mp.find(presum)!=mp.end()){
                len=max(len,i-mp[presum]);
            }
            else{
                mp[presum]=i;
            }
        }
        return len;
    }
};