class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> minVal(n, INT_MAX);
        minVal[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            minVal[i] = min({minVal[i], nums[i], minVal[i+1]});
        }
        int maxVal = INT_MIN;
        for(int i = 0; i< n; i++){
            maxVal = max(maxVal, nums[i]);
            if((maxVal - minVal[i]) <= k){
                return i;
            }
        }
        return -1;
    }
};