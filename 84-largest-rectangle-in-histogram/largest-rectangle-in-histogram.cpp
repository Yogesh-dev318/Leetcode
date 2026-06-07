class Solution {
public:
    vector<int> RSN(vector<int>& heights){
        int n=heights.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> LSN(vector<int>& heights){
        int n=heights.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right = RSN(heights);
        vector<int> left = LSN(heights);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long width = right[i] - left[i] - 1;
            long long area = width * heights[i];
            ans = max(ans, area);
        }
        return ans;
    }
};