class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++){
            adj[parent[i]].push_back(i);
        }

        vector<int> new_parent = parent;
        vector<int> last_seen(26, -1);
        auto dfsFindParent = [&](auto & self, int u) -> void{
            int char_idx= s[u]-'a';
            int prev_ances = last_seen[char_idx];
            if(prev_ances != -1){
                new_parent[u] = prev_ances;
            }
            last_seen[char_idx] = u;
            for(int v : adj[u]){
                self(self, v);
            }
            last_seen[char_idx] = prev_ances;
        };
        dfsFindParent(dfsFindParent, 0);
        vector<vector<int>> finalAdj(n);
        for(int i= 1; i < n; i++){
            finalAdj[new_parent[i]].push_back(i);
        }

        vector<int> ans(n, 0);
        auto dfsCountSizes = [&](auto & self, int u)-> int {
            int count = 1;
            for(auto v : finalAdj[u]){
                count += self(self, v);
            }
            ans[u] = count;
            return count;
        };
        dfsCountSizes(dfsCountSizes, 0);
        return ans;

    }
};