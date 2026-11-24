class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;
        long long pro =1;
        int l= 0;
        for(int r = 0; r < n; r++){
            while(gcd(pro, (long long)nums[r]) > 1){
                pro /= nums[l];
                l++;
            }
            pro *= nums[r];
            ans = max(ans, (r- l + 1));
        }
        return ans;
    }
};