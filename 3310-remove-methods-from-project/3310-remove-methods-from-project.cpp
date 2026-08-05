class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto const &inv : invocations){
            adj[inv[0]].push_back(inv[1]);
        }

        vector<bool> sus(n, false);
        vector<int> q;
        q.push_back(k);
        sus[k] = true;
        int head = 0;
        while(head < (int)q.size()){
            int u = q[head++];
            for(int v : adj[u]){
                if(!sus[v]){
                    sus[v] = true;
                    q.push_back(v);
                }
            }
        }

        for(const auto &inv: invocations){
            int u = inv[0], v = inv[1];
            if(!sus[u] && sus[v]){
                vector<int> allMethod(n);
                iota(allMethod.begin(), allMethod.end(), 0);
                return allMethod;
            }
        }

        vector<int> ans;
        for(int i = 0; i< n; i++){
            if(!sus[i]){
                ans.push_back(i);
            }
        
        }
        return ans;
    }
};