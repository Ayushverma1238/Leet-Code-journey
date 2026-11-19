class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int aux1 = nums[n-1] - nums[2];
        int aux2 = nums[n-3] - nums[0];
        int aux3 = nums[n-2] - nums[1];
        return min({aux1, aux2, aux3});
    }
};