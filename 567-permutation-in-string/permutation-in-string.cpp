class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> mp1,mp2;
        int l=0;
        for(int i=0;i<s1.size();i++){
            mp1[s1[i]]++;
        }
        for(int i=0;i<s2.size();i++){
            mp2[s2[i]]++;
            if(i-l+1>s1.size()){
                mp2[s2[l]]--;
                if(mp2[s2[l]]==0){
                    mp2.erase(s2[l]);
                }
                l++;
            }
            if(i-l+1==s1.size() && mp1==mp2){
                return true;
            }
        }
        return false;
    }
};