class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        // if(n == 0) return -1;
        vector<int> minElem(n, INT_MAX);
        minElem[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            minElem[i] = min({minElem[i], nums[i], minElem[i+1]});
        }
        int maxElem = INT_MIN;
        for(int i = 0; i< n; i++){
            maxElem = max(maxElem, nums[i]);
            if((maxElem - minElem[i]) <= k){
                return i;
            }
        }
        return -1;
    }
};