#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If the start or end cell itself has a thief, safeness factor is 0
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }
        
        // Step 1: Multi-source BFS to find distance to the nearest thief
        // Initialize with -1 to track unvisited cells cleanly
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!q.empty()) {
            auto [curr_r, curr_c] = q.front();
            q.pop();
            
            for (auto [dr, dc] : dir) {
                int next_r = curr_r + dr;
                int next_c = curr_c + dc;
                
                if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n) {
                    // Only push if it hasn't been visited yet (-1)
                    if (dist[next_r][next_c] == -1) {
                        dist[next_r][next_c] = dist[curr_r][curr_c] + 1;
                        q.push({next_r, next_c});
                    }
                }
            }
        }
        
        // Step 2: Dijkstra's Algorithm with Max-Heap to find maximum safeness factor path
        // Tuple format: {safeness_factor, r, c}
        priority_queue<tuple<int, int, int>> maxHeap;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        maxHeap.push({dist[0][0], 0, 0});
        visited[0][0] = true;
        
        while (!maxHeap.empty()) {
            auto [curr_safe, r, c] = maxHeap.top();
            maxHeap.pop();
            
            // If we reached the destination, this path's safeness is maximized
            if (r == n - 1 && c == n - 1) {
                return curr_safe;
            }
            
            for (auto [dr, dc] : dir) {
                int next_r = r + dr;
                int next_c = c + dc;
                
                if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n && !visited[next_r][next_c]) {
                    visited[next_r][next_c] = true;
                    
                    // The path safeness is bottlenecked by the minimum distance met so far
                    int next_safe = min(curr_safe, dist[next_r][next_c]);
                    maxHeap.push({next_safe, next_r, next_c});
                }
            }
        }
        
        return 0;
    }
};