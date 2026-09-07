class Solution {
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    long long nCr(int n, int r) {
        if (r < 0 || r > n)
            return 0;

        r = min(r, n - r); // Optimization

        long long result = 1;

        for (int i = 1; i <= r; i++) {
            result = (result * (n - r + i) % MOD) / i;
        }

        return result;
    }

public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {

        unordered_map<char, int> freq;
        for (auto c : s) {
            freq[c]++;
        }
        if (k > freq.size())
            return 0;
       vector<int> counts;
        for (auto& [ch, f] : freq) counts.push_back(f);
        sort(counts.rbegin(), counts.rend());

        int target_freq = counts[k - 1];
        int count_greater = 0, count_equal = 0;

        for (int f : counts) {
            if (f > target_freq) count_greater++;
            else if (f == target_freq) count_equal++;
        }

        long long ans = 1;

        // Multiply choices for characters strictly larger than target_freq
        for (int i = 0; i < count_greater; i++) {
            ans = (ans * counts[i]) % MOD;
        }

        // Combinations to choose remaining characters from ties
        int rem = k - count_greater;
        long long combinations = nCr(count_equal, rem);
        ans = (ans * combinations) % MOD;

        // Multiply choices for the remaining characters
        ans = (ans * power(target_freq, rem)) % MOD;

        return ans;
    }
};