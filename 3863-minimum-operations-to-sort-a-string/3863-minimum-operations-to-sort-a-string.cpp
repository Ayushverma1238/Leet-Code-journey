class Solution {
public:
    int minOperations(string s) {
        bool isSort = true;
        int n = s.size();
        int minIdx = 0, maxIdx = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) {
                isSort = false;
                // break;
            }
            if (s[i] < s[minIdx]) {
                minIdx = i;
            }
            if (s[i] >= s[maxIdx])
                maxIdx = i;
        }
        if (isSort)
            return 0;
        if (n == 2) {
            return -1;
        }

        if (minIdx == 0 || maxIdx == n - 1) {
            return 1;
        }
        if (minIdx == n - 1 && maxIdx == 0) {
            return 3;
        }
        return 2;
    }
};