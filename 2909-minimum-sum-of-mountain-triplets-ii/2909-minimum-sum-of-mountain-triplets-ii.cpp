class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n= nums.size();
        vector<int> leftMax(n, INT_MIN);
        vector<int> rightMin(n, INT_MAX);
        leftMax[0] = nums[0];
        rightMin[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            leftMax[i] = min(leftMax[i-1], nums[i]);
            rightMin[n-i-1] = min(rightMin[n-i], nums[n-i-1]);
        }
        
        int ans = INT_MAX;
        for(int i =1; i < n-1; i++){
            if(nums[i] > leftMax[i-1] && nums[i] > rightMin[i+1]){
                ans = min(ans, nums[i] + leftMax[i-1] + rightMin[i+1]);
            }
        }
        return (ans == INT_MAX) ? -1: ans;
    }
};