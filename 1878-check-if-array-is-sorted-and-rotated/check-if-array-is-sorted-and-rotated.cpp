class Solution {
public:
    bool check(vector<int>& nums) {
        
        int check=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                check++;
                if(check>1){
                    return false;
                }
            }
        }
        if(nums[0]<nums[nums.size()-1]){
            check++;
        }
        return check<=1;

    }
};