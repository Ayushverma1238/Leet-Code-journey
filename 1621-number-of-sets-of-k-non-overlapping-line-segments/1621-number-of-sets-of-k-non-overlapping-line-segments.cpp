class Solution {
    const int MOD = 1e9 + 7;
    
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int numberOfSets(int n, int k) {
        long long total_points = n + k - 1;
        long long r = 2 * k;

        if (r > total_points) return 0;

        long long num = 1, den = 1;
        for (int i = 0; i < r; ++i) {
            num = (num * (total_points - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }

        return (num * modInverse(den)) % MOD;
    }
};