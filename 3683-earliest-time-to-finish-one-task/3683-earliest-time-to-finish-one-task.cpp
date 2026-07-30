class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans = INT_MAX;
        for(auto n : tasks){
            ans = min(ans, n[0] + n[1]);
        }
        return ans;
    }
};