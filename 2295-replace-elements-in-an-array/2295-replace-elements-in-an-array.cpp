class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int pos[1000001]; // Direct index array for O(1) guaranteed access
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        for (const auto& val : operations) {
            int idx = pos[val[0]];
            pos[val[1]] = idx;
            nums[idx] = val[1];
        }

        return nums;
    }
};