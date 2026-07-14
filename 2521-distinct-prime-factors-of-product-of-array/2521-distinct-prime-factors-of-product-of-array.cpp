class Solution {
    unordered_set<int> s;
    void primeFactor(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                s.insert(i);
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        if (n > 1) {
            s.insert(n);
        }
    }

public:
    int distinctPrimeFactors(vector<int>& nums) {
        for (auto n : nums) {
            primeFactor(n);
        }

        return s.size();
    }
};