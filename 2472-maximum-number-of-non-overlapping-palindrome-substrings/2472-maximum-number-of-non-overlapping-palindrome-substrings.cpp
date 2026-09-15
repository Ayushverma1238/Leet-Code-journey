class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        
        // 1. Preprocess the string for Manacher's algorithm
        string t = "^";
        for (char c : s) {
            t += "#";
            t += c;
        }
        t += "#$";

        int m = t.size();
        vector<int> P(m, 0);
        int C = 0, R = 0;

        // 2. Standard Manacher's Algorithm
        for (int i = 1; i < m - 1; ++i) {
            int i_mirror = 2 * C - i;
            if (R > i) {
                P[i] = min(R - i, P[i_mirror]);
            }

            while (t[i + 1 + P[i]] == t[i - 1 - P[i]]) {
                P[i]++;
            }

            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        // Helper function to check if s[l..r] is a palindrome in O(1)
        auto isPalindrome = [&](int l, int r) {
            // Map original 0-indexed [l, r] to transformed string index center & radius
            int center = l + r + 2; 
            int radius = r - l + 1;
            return P[center] >= radius;
        };

        // 3. Greedy Matching
        int count = 0;
        int last_end = -1; // End index of the previous selected palindrome

        for (int r = k - 1; r < n; ++r) {
            // Check for palindrome of length k ending at r
            int l1 = r - k + 1;
            if (l1 > last_end && isPalindrome(l1, r)) {
                count++;
                last_end = r;
                continue;
            }

            // Check for palindrome of length k + 1 ending at r
            int l2 = r - k;
            if (l2 > last_end && isPalindrome(l2, r)) {
                count++;
                last_end = r;
            }
        }

        return count;
    }
};