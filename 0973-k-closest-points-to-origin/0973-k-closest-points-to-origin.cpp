class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<long long, vector<vector<int>>> mp;

        for(auto p : points){
            int x= p[0], y = p[1];

            long long key = x * x + y * y;
            mp[key].push_back(p);
        }
        vector<vector<int>> ans;
        for(auto it : mp){
            int n = it.second.size();
            int i = 0;
            while(k > 0 && i < n){
                ans.push_back(it.second[i]);
                k--;
                i++;
            }
        }
        return ans;
    }
};