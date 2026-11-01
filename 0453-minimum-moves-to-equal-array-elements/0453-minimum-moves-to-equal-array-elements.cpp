class Solution {
public:
    int minMoves(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int minElem = nums[0];

        // int ans = 0;
        // for(int i = nums.size()-1; i>= 0; i--){
        //     ans += nums[i] - minElem;
        // }
        // return ans;
        int minElem = INT_MAX;
        int sum = 0;
        for(auto n : nums){
            sum += n;
            minElem = min(minElem, n);
        }

        return (sum - minElem * nums.size());
    }
};