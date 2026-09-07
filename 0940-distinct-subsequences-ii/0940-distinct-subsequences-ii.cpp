class Solution {
    int mod = 1e9 + 7;

public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 1);

        vector<int> last(26, -1);
        for (int i = 0; i < n; i++) {
            int lastIdx = s[i] - 'a';
            dp[i + 1] = (dp[i] * 2) % mod;
            if (last[lastIdx] != -1) {
                dp[i + 1] = (dp[i + 1] - dp[last[lastIdx]] + mod) % mod;
            }
            last[lastIdx] = i;
        }
        return (dp[n] - 1 + mod) % mod;
    }
};