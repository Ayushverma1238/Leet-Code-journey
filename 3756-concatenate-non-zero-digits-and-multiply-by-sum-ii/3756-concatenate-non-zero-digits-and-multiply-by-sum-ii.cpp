class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        
        vector<long long> cnt(n+1, 0), sumd(n+1, 0), val(n+1, 0);
        vector<long long> pow10(n+1, 1);

        // Precompute powers of 10
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i-1] * 10) % MOD;

        // Build prefix arrays
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            cnt[i+1] = cnt[i];
            sumd[i+1] = sumd[i];
            val[i+1] = val[i];

            if (d != 0) {
                cnt[i+1] = cnt[i] + 1;
                sumd[i+1] = (sumd[i] + d) % MOD;
                val[i+1] = (val[i] * 10 + d) % MOD;
            }
        }

        int q = queries.size();
        vector<int> ans(q);

        // Process each query in O(1)
        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            long long k = cnt[r+1] - cnt[l];
            long long sum = (sumd[r+1] - sumd[l] + MOD) % MOD;

            long long x = (val[r+1] - val[l] * pow10[k] % MOD + MOD) % MOD;

            ans[i] = (x * sum) % MOD;
        }

        return ans;
    }
};
