class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> NSEL(n);
        vector<int> NSER(n);
        vector<int> NGEL(n);
        vector<int> NGER(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                NSEL[i]=-1;
            }
            else{
                NSEL[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty()){
                NSER[i]=n;
            }
            else{
                NSER[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                NGEL[i]=-1;
            }
            else{
                NGEL[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(st.empty()){
                NGER[i]=n;
            }
            else{
                NGER[i]=st.top();
            }
            st.push(i);
        }
        long long maxs=0;
        long long mins=0;
        for(int i=0;i<n;i++){
            long long sl=i-NSEL[i];
            long long sr=NSER[i]-i;
            mins=mins + ((sl*sr)*nums[i]);

            long long ll=i-NGEL[i];
            long long lr=NGER[i]-i;
            maxs=maxs + ((ll*lr)*nums[i]);

        }
        return maxs-mins;
        // int n=nums.size();
        // long long sum=0;
        // for(int i=0;i<n;i++){
        //     int mini=nums[i];
        //     int maxi=nums[i];
        //     for(int j=i;j<n;j++){
        //         mini=min(mini,nums[j]);
        //         maxi=max(maxi,nums[j]);
        //         sum=sum+(maxi-mini);
        //     }
        // }
        // return sum;
    }
};