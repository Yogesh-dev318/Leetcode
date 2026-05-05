class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        // set<int> st;
        // for(int i=0;i<n;i++){
        //     st.insert(nums[i]);
        // }
        // int t=0;
        // for(auto it : st){
        //     nums[t]=it;
        //     t++;
        // }
        // return t;
        int i=0;
        for(int j=i;j<n;j++){
            if(nums[i]!=nums[j]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;


    }
};