#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    int memo[101][101];
    vector<int> suffixSum;
    int n;

    int solve(int i, int M) {
        if (i + 2 * M >= n) {
            return suffixSum[i];
        }

        if (memo[i][M] != -1) {
            return memo[i][M];
        }

        int maxStones = 0;

        for (int X = 1; X <= 2 * M; ++X) {
            int nextM = max(M, X);
            int currentStones = suffixSum[i] - solve(i + X, nextM);
            maxStones = max(maxStones, currentStones);
        }

        return memo[i][M] = maxStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffixSum.assign(n, 0);
        
        for (int i = 0; i < 101; ++i) {
            fill(memo[i], memo[i] + 101, -1);
        }

        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        return solve(0, 1);
    }
};