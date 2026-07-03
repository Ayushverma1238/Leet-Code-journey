class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> ans(n, false);
        int m = pattern.size();
        for (int k = 0; k < n; k++) {
            string s = queries[k];
            int i = 0, j = 0;
            bool isBreak = false;
            while (i < s.size() && j < m) {
                if (s[i] == pattern[j]) {
                    i++;
                    j++;
                } else {
                    if (s[i] >= 'A' && s[i] <= 'Z') {
                        isBreak = true;
                        ans[k] = false;
                        break;
                    }
                    i++;
                }
            }
            if (j == pattern.size() && !isBreak) {
                while (i < s.size()) {
                    if (s[i] >= 'A' && s[i] <= 'Z') {
                        ans[k] = false;
                        break;
                    } else
                        i++;
                }
                if (i == s.size())
                    ans[k] = true;
            }
        }
        return ans;
    }
};