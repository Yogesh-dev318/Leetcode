class Solution {
public:
    bool pal(string &ans,int i,int j){
        if(i>=j){
            return true;
        }
        // else if(ans[i]==ans[j]){
        //     return ;
        // }
        else if(ans[i]!=ans[j]){
            return false;
        }
        return pal(ans,i+1,j-1);
    }
    bool isPalindrome(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                ans+=tolower(s[i]);
            }
        }
        return pal(ans,0,ans.size()-1);
    }
};