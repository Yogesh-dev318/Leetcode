class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        if (m > n) return ans;
        unordered_map<char, int> mpP, mpS;
        for (char c : p)
            mpP[c]++;
        int l = 0;
        for (int r = 0; r < n; r++) {
            mpS[s[r]]++;
            if (r - l + 1 > m) {
                mpS[s[l]]--;
                if (mpS[s[l]] == 0)
                    mpS.erase(s[l]);
                l++;
            }
            if (r - l + 1 == m && mpS == mpP)
                ans.push_back(l);
        }
        return ans;
    }
};