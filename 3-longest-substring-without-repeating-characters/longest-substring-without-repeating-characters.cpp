class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int count=0;
        int ans=INT_MIN;
        // for(int i=0;i<n;i++){
        //     while(i<n){
        //         if(st.find(s[i])==st.end()){
        //             count++;
        //             st.insert(s[i]);
        //             ans=max(ans,count);
        //         }
        //         else{
        //             st.clear();
        //             count=1;
        //             st.insert(s[i]);
        //             ans=max(ans,count);
        //         }
        //         i++;
        //     }
        // }
        // return ans == INT_MIN ? 0 : ans;
        for(int i=0;i<n;i++){
            set<char> st;
            for(int j=i;j<n;j++){
                if(st.find(s[j])!=st.end()){
                    break;
                }
                st.insert(s[j]);
                ans=max(ans,j-i+1);
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};