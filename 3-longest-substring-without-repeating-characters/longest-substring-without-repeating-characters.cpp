class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        // int count=0;
        // int ans=INT_MIN;
        
        // for(int i=0;i<n;i++){
        //     set<char> st;
        //     for(int j=i;j<n;j++){
        //         if(st.find(s[j])!=st.end()){
        //             break;
        //         }
        //         st.insert(s[j]);
        //         ans=max(ans,j-i+1);
        //     }
        // }
        // return ans == INT_MIN ? 0 : ans;
        map<char, int> mp;
        int l = 0;
        int ans = 0;
        for (int r = 0; r < n; r++) {
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
            }
            mp[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
    
};