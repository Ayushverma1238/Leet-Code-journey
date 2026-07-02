class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> max_k(m, vector<int>(n, -1));
max_k[0][0] = k;
        queue<pair<int, pair<int, pair<int, int>>>> q;
        q.push({0, {0, {k, 0}}});
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // int steps = 0;
        while (!q.empty()) {
            auto [r, ck] = q.front();
            q.pop();
            auto [c, cs] = ck;
            auto [k, curr_s] = cs;
            if (r == m - 1 && c == n - 1 && k >= 0) {
                return curr_s;
            }

            for (auto [dr, dc] : dir) {
                int new_r = dr + r;
                int new_c = dc + c;

                if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n) {
                int next_k = k - grid[new_r][new_c];
                
                if (next_k >= 0 && next_k > max_k[new_r][new_c]) {
                    max_k[new_r][new_c] = next_k;
                    q.push({new_r,{ new_c, {next_k, curr_s + 1}}});
                }
            }
            }
            // steps++;
        }
        return -1;
    }
};