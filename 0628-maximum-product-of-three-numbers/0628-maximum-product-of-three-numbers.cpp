class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        int n = nums.size();
        for(int i =0; i< (n-3+1);i++){
            ans = max(ans, (nums[i] * nums[i+1] * nums[n-1]));
        }
        return ans;
    }
};