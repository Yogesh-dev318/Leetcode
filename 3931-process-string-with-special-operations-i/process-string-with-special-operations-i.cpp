class Solution {
public:
    string processStr(string s) {
        vector<char> res;
        for (auto ch : s) {
            if (ch == '*') {
                if (!res.empty()) {
                    res.pop_back();
                }
            }
            else if (ch == '#') {
                int sz = res.size();
                for (int i = 0; i < sz; i++) {
                    res.push_back(res[i]);
                }
            }
            else if (ch == '%') {
                reverse(res.begin(), res.end());
            }
            else if (ch >= 'a' && ch <= 'z') {
                res.push_back(ch);
            }
        }
        return string(res.begin(), res.end());
    }
};