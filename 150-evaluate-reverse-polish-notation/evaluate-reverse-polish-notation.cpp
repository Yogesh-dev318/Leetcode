class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=(tokens[i]=="+") ? (a+b) : (tokens[i]=="-") ? (b-a) : (tokens[i]=="*") ? (a*b) : (b/a);
                st.push(c);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};