class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // If the start or end is blocked, there are 0 paths
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0;
        
        // Initialize DP table with 0s (representing 0 paths initially)
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        
        // Base case: The destination has 1 valid path (standing on it)
        dp[m-1][n-1] = 1;
        
        // Traverse backwards
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // If it's an obstacle, 0 paths go through here
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    // Add paths from the cell below (if within bounds)
                    if (i + 1 < m) dp[i][j] += dp[i+1][j];
                    // Add paths from the cell to the right (if within bounds)
                    if (j + 1 < n) dp[i][j] += dp[i][j+1];
                }
            }
        }
        
        return dp[0][0];
    }
};