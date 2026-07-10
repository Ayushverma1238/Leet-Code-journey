class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // 1. Pair value with original index and sort
        vector<pair<int, int>> sorted_nodes(n);
        for(int i = 0; i < n; ++i) {
            sorted_nodes[i] = {nums[i], i};
        }
        sort(sorted_nodes.begin(), sorted_nodes.end());
        
        // Map original index to sorted index for fast lookup during queries
        vector<int> original_to_sorted(n);
        for(int i = 0; i < n; ++i) {
            original_to_sorted[sorted_nodes[i].second] = i;
        }
        
        // 2. Compute 2^0 jumps using two pointers
        int LOG = 18; // since 2^17 = 131,072 > 10^5
        vector<vector<int>> up(n, vector<int>(LOG));
        
        int r = 0;
        for(int l = 0; l < n; ++l) {
            while(r < n && sorted_nodes[r].first - sorted_nodes[l].first <= maxDiff) {
                r++;
            }
            // r - 1 is the furthest reachable node from l
            up[l][0] = r - 1;
        }
        
        // 3. Fill the binary lifting sparse table
        for(int j = 1; j < LOG; ++j) {
            for(int i = 0; i < n; ++i) {
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
        
        // 4. Process Queries
        vector<int> ans;
        for(auto& q : queries) {
            int u = original_to_sorted[q[0]];
            int v = original_to_sorted[q[1]];
            
            if(u == v) {
                ans.push_back(0);
                continue;
            }
            if(u > v) swap(u, v); // ensure we always lift from left to right
            
            int jumps = 0;
            int curr = u;
            
            // Lift curr as far as possible without reaching or passing v
            for(int j = LOG - 1; j >= 0; --j) {
                if(up[curr][j] < v) {
                    jumps += (1 << j);
                    curr = up[curr][j];
                }
            }
            
            if(up[curr][0] >= v) {
                jumps += 1;
                curr = up[curr][0];
            }
            
            if(curr >= v) {
                ans.push_back(jumps);
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};