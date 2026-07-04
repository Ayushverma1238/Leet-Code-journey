class Solution {
   
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> m;
        for(auto e : roads){
            m[e[0]].push_back({e[1],e[2]});
            m[e[1]].push_back({e[0],e[2]});
        }

        queue<int>q;
        q.push(1);
        vector<int> visited(n+1, 0);
        visited[1] = true;
        int ans = INT_MAX;
        while(!q.empty()){
            auto curr = q.front();q.pop();
            for(auto ne : m[curr]){
                auto [v,w] = ne;
                ans = min(ans, w);
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};