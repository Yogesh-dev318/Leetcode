class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]==')'||s[i]==']'||s[i]=='}'){
                if(st.empty()) return false;
                if(s[i]==')' && st.top()=='('){
                    st.pop();
                    continue;
                }
                if(s[i]==']' && st.top()=='['){
                    st.pop();
                    continue;
                }
                if(s[i]=='}' && st.top()=='{'){
                    st.pop();
                    continue;
                }
                return false;
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.size()==0){
            return true;
        }
        return false;
    }
};