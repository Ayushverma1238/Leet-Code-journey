class Solution {
    int m, n;
    int memo[101][101][101];
    bool solve(vector<vector<char>>& grid, int r, int c, int curr) {
        if (curr < 0 || curr > 100) {
            return false;
        }
        if (r == m - 1 && c == n - 1) {
            return curr == 0;
        }
        if (memo[r][c][curr] != -1)
            return memo[r][c][curr];

        bool possible = false;
        if (c + 1 < n) {
            int nextCurr = curr + (grid[r][c + 1] == '(' ? 1 : -1);
            possible |= solve(grid, r, c + 1, nextCurr);
        }
        if (r + 1 < m) {
            int nextCurr = curr + (grid[r+1][c] == '(' ? 1 : -1);
            possible |= solve(grid, r+1, c, nextCurr);
        }
        return memo[r][c][curr] = possible;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>
        // (2, 0))); dp[0][0][0] = (grid[0][0] == '(') ? 1 : -1; dp[0][0][1] =
        // (grid[0][0] == '(') ? 1 : -1;

        // for(int i = 1; i < n; i++){
        //     dp[0][i][0] = dp[0][i][0] + ((grid[0][i] == '(') ? 1 : -1);
        //     dp[0][i][0] = dp[0][i][1] + ((grid[0][i] == '(') ? 1 : -1);
        // }
        // for(int i =1; i < m; i++){
        //     dp[i][0][0] = dp[i][0][0] + ((grid[i][0] == '(') ? 1 : -1);
        //     dp[i][0][1] = dp[i][0][1] + ((grid[i][0] == '(') ? 1 : -1);
        // }

        // for(int i =1 ; i< m; i++){
        //     for(int j = 1; j < n; j++){
        //         dp[i][j][0] = dp[i][j-1][0] + ((grid[i][0] == '(') ? 1 : -1);
        //         dp[i][j][1] = dp[i-1][j][1] + ((grid[i][0] == '(') ? 1 : -1);
        //     }
        // }

        // return dp[m-1][n-1][0] == 0 || dp[m-1][n-1][1] == 0;
        if((m + n -1) % 2 != 0 | grid[0][0] == ')') return false;
        memset(memo, -1, sizeof(memo));
        return solve(grid, 0, 0, 1);
    }
};