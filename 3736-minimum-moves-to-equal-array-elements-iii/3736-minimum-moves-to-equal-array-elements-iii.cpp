class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(auto n : nums){
            ans += abs(maxEle - n);
        }
        return ans;
    }
};