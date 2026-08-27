class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        // Try to find the position i where result[i] > target[i]
        // while result[0...i-1] == target[0...i-1]
        for (int i = n - 1; i >= -1; i--) {
            // Validate if we can match target[0...i-1]
            vector<int> freq = count;
            bool possible = true;
            for (int j = 0; j < i; j++) {
                int idx = target[j] - 'a';
                if (freq[idx] > 0) {
                    freq[idx]--;
                } else {
                    possible = false;
                    break;
                }
            }

            if (!possible) continue;

            // If i == -1, we can't match any prefix, break out
            if (i == -1) break;

            // Try to place a character strictly greater than target[i]
            for (int ch = target[i] - 'a' + 1; ch < 26; ch++) {
                if (freq[ch] > 0) {
                    // Build the answer
                    string ans = target.substr(0, i);
                    ans += (char)('a' + ch);
                    freq[ch]--;

                    // Fill remaining positions with the smallest available characters
                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += (char)('a' + k);
                            freq[k]--;
                        }
                    }
                    return ans;
                }
            }
        }

        return "";
    }
};