class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        deque < pair<int, pair<int, int>>> dq;
        dq.push_back({0, {0, health - grid[0][0]}});
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visited[0][0] = true;
        while (!dq.empty()) {
            auto [r, cp] = dq.front();
            auto [c, curr_h] = cp;
            if (r == m - 1 && c == n - 1 && curr_h > 0) {
                return true;
            }
            dq.pop_front();
            for (auto [dr, dc] : dir) {
                int new_r = r + dr;
                int new_c = c + dc;
                if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n &&
                    !visited[new_r][new_c]) {
                    if (grid[new_r][new_c] == 1) {
                        dq.push_back({new_r, {new_c, curr_h - 1}});
                    } else {
                        dq.push_front({new_r, {new_c, curr_h}});
                    }
                    visited[new_r][new_c] = true;
                }
            }
        }
        return false;
    }
};