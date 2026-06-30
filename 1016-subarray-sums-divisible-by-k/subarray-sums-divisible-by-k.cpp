class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int presum=0;
        int cnt=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int mod=presum%k;
            if(mod<0){
                mod=mod+k;
            }
            if(mp.find(mod)!=mp.end()){
                cnt=cnt+mp[mod];
                mp[mod]++;
            }
            else{
                mp[mod]=1;
            }
        }
        return cnt;
    }
};