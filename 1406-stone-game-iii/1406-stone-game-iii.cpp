#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // dp[i] stores the max score difference current player can get from index i
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int takeSum = 0;
            dp[i] = -1e9; // Initialize with a very small number

            for (int k = 0; k < 3 && i + k < n; ++k) {
                takeSum += stoneValue[i + k];
                dp[i] = max(dp[i], takeSum - dp[i + k + 1]);
            }
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};