class Solution {
public:
    void solve(int index,string output,string digits,vector<string>& ans,string mapping[]){
        if(index==digits.size()){
            ans.push_back(output);
            return;
        }
        int num=digits[index] - '0';
        string mapp=mapping[num];
        for(int i=0;i<mapp.size();i++){
            solve(index+1,output+mapp[i],digits,ans,mapping);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        string output;
        int index=0;
        string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(index,output,digits,ans,mapping);
        return ans;
    }
};