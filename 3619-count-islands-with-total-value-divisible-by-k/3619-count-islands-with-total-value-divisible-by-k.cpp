class Solution {
    int m, n;
    long long solve(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }

        long long val = grid[r][c];
        grid[r][c] = 0;
        return val + solve(grid, r - 1, c) + solve(grid, r + 1, c) +
               solve(grid, r, c - 1) + solve(grid, r, c + 1);
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for(int i =0; i <m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0){
                    long long val = solve(grid, i, j);
                    if(val % k == 0){
                        ans++;
                    }
                }
            }
        }
        return ans;

        // Queue approch
       /* vector<int> dirx = {-1, 1, 0, 0};
        vector<int> diry = {0, 0, -1, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    long long totalVal = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    totalVal = grid[i][j];
                    grid[i][j] = 0;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int newx = x + dirx[d];
                            int newy = y + diry[d];
                            if (newx >= 0 && newx < m && newy >= 0 &&
                                newy < n && grid[newx][newy] != 0) {
                                totalVal += grid[newx][newy];
                                grid[newx][newy] = 0;
                                q.push({newx, newy});
                            }
                        }
                    }
                    if(totalVal % k == 0)
                        ans++;
                }
            }
        }
        return ans;*/
    }
};