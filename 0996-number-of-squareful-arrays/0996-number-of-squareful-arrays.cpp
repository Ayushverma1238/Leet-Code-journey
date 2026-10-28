class Solution {
    int ans = 0;
    vector<int> aux;
    vector<bool> used;
    void solve(vector<int>& nums) {
        if (aux.size() == nums.size()) {
            ans++;
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            if (!aux.empty()) {
                long long val = (long long)aux.back() + (long long)nums[i];
                long long sq = sqrt(val);
                if (sq * sq != val)
                    continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            aux.push_back(nums[i]);
            used[i] = true;
            solve(nums);
            aux.pop_back();
            used[i] = false;
        }
    }

public:
    int numSquarefulPerms(vector<int>& nums) {
        used.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        solve(nums);
        return ans;
    }
};