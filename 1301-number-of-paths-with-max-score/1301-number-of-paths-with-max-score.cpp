class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;

        // dp[i][j] stores {max_score, path_count}
        // Initialize with -1 score to represent unreachable/unvisited states
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));

        // Base case: Start at the bottom-right corner 'S'
        dp[n - 1][n - 1] = {0, 1};

        // Directions we look back to: bottom, right, bottom-right
        int dirs[3][2] = {{1, 0}, {0, 1}, {1, 1}};

        // Process from bottom to top, right to left
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // Skip the starting point (already initialized) or obstacles
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) continue;

                int best_score = -1;
                long long total_paths = 0;

                // Check all 3 incoming paths
                for (auto& d : dirs) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    // Ensure bounds and that the incoming cell is reachable
                    if (ni < n && nj < n && dp[ni][nj].first != -1) {
                        if (dp[ni][nj].first > best_score) {
                            best_score = dp[ni][nj].first;
                            total_paths = dp[ni][nj].second;
                        } else if (dp[ni][nj].first == best_score) {
                            total_paths = (total_paths + dp[ni][nj].second) % MOD;
                        }
                    }
                }

                // If at least one valid incoming path exists, update current cell
                if (best_score != -1) {
                    int current_val = (board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                    dp[i][j] = {best_score + current_val, total_paths};
                }
            }
        }

        // Target is top-left 'E' at dp[0][0]
        if (dp[0][0].first == -1) {
            return {0, 0};
        }
        return {dp[0][0].first, dp[0][0].second};
    }
};