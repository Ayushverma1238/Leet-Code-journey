class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k0 = bit_ceil((unsigned) n) -1;
        int k = k0;
        for(int i =0; i< n; i++){
            if(nums[i] != i){
                k &= nums[i];
            }
        }
        return (k == k0) ? 0: k;
    }
};