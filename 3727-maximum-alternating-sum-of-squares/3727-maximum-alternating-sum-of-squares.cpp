class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [&](int &a, int & b) {
            return abs(a) < abs(b);
        });
        long long ans = 0;
        int half = n/2;
        for(int i = 0;i < n; i++){
            if(i < half){
                ans -= (nums[i] * nums[i]);
            }else{
                ans += (nums[i] * nums[i]);
            }

        }
        return ans;
    }
};