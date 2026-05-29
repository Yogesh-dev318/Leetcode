class Solution {
public:
    int fun(vector<int>& nums,int k){
        int n=nums.size();
        int l=0;
        int r=0;
        int cnt=0;
        map<int,int> mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        // int count=0;
        // for(int i=0;i<n;i++){
        //     set<int> st;
        //     for(int j=i;j<n;j++){
        //         st.insert(nums[j]);
        //         if(st.size()==k){
        //             count++;
        //         }
        //     }
        // } 
        // return count;
        int ans=fun(nums,k)-fun(nums,k-1);
        return ans;
    }
};