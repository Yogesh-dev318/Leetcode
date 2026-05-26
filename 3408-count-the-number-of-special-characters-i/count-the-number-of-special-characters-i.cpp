class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[word[i]]++;
        }
        int count=0;
        for(char ch='a';ch<='z';ch++){
            if(mp[ch]>0 && mp[toupper
            (ch)]>0){
                count++;
            }
        }
        return count;
    }
};