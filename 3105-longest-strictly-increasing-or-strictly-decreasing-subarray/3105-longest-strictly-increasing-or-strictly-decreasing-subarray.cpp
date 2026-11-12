class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int k = 0;
        int ans = 0;
        for(int j = 1; j < n; j++){
            if(nums[j] <= nums[j-1]){
                ans= max(ans, (j- i));
                i = j;
            }

            if(nums[j] >= nums[j-1]){
                ans = max(ans, j- k);
                k = j;
            }
        }

        ans = max({ans, (n- i), (n -k)});
        return ans;
    }
};