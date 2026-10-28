class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;
    void solve(vector<int>& nums) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            used[i] = true;
            path.push_back(nums[i]);
            solve(nums);
            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        solve(nums);
        return ans;
    }
};