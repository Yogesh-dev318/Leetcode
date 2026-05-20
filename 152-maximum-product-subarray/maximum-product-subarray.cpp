class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pre=1;
        int maxpre=INT_MIN;
        int suf=1;
        int maxsuf=INT_MIN;
        int ans;
        for(int i=0;i<n;i++){
            pre=pre*nums[i];
            
            maxpre=max(pre,maxpre);
            if(pre==0){
                pre=1;
            }
        }
        for(int i=n-1;i>=0;i--){
            suf=suf*nums[i];
            
            maxsuf=max(suf,maxsuf);
            if(suf==0){
                suf=1;
            }
        }
        ans=max(maxpre,maxsuf);
        return ans;
    }
};