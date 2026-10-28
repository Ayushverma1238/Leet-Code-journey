class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        dp[0][0].set(grid[0][0]);
        for(int j = 1;j < n; j++){
            for(int x= 0; x < 1024; x++){
                if(dp[0][j-1].test(x)){
                    dp[0][j].set(x^grid[0][j]);
                }
            }
        }
        for(int i= 1; i < m; i++){
            for(int x = 0; x < 1024; x++){
                if(dp[i-1][0].test(x)){
                    dp[i][0].set(x^grid[i][0]);
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                std::bitset<1024> reachable = dp[i-1][j] | dp[i][j-1];
                for(int x = 0;x< 1024; x++){
                    if(reachable.test(x)){
                        dp[i][j].set(x^grid[i][j]);
                    }
                }
            }
        }
        for(int x = 0; x < 1024; x++){
            if(dp[m-1][n-1].test(x)){
                return x;
            }
        }
        return 0;
    }
};