class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n = grid[0].size();
        k %= (m*n);
        if(k == 0)return grid;
        int r = k/n;
        int c = k %n;
        vector<vector<int>> ans(m, vector<int> (n,0));
        for(int i = 0; i < m; i++){
            for(int j=0;j < n;j++){
                ans[r][c] = grid[i][j];

                c = (c + 1) % n;
                if(c == 0){
                    r = (r + 1) % m;
                }
            }
        }

        return ans;
    }
};