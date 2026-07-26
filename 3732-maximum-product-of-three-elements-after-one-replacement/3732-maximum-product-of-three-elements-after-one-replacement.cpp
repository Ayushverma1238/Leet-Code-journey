class Solution {
public:

    long long maxProduct(vector<int>& nums) {
        // int firstMax = INT_MIN+1, secondMax = INT_MIN +1;
        int n = nums.size();
        // for(int i = 0; i< n; i++){
        //     if(abs(nums[i]) >= abs(firstMax)){
        //         secondMax = firstMax;
        //         firstMax = nums[i];
        //     } else if(abs(nums[i]) >= abs(secondMax))
        //         secondMax = nums[i];
            
        // }
        // long long ans = 1LL * firstMax * secondMax;

        // sort(nums.begin(), nums.end());

        // // long long ans = max({1LL * nums[0] * nums[1], 1LL * nums[0] * nums[n-1], 1LL * nums[n-1] * nums[n-2]});
        // long long ans = 1LL * nums[0] * nums[1];
      
        // long long pro = 1LL * nums[0] * nums[n-1];
        // if(abs(pro) >= abs(ans)){
        //     ans = pro;
        // }
        // pro = 1LL * nums[n-1] * nums[n-2];
        // if(abs(pro) >= abs(ans)){
        //     ans = pro;
        // }
        // return (ans < 0) ? 1LL *ans * (-100000) : 1LL *ans * 100000;
        int firstMax = INT_MIN, secondMax = INT_MIN;

        for(int i = 0; i< n; i++){
            int val = (nums[i] < 0) ? -1 *nums[i] : nums[i];
            if(val >= firstMax){
                secondMax = firstMax;
                firstMax = val;
            }else{
                secondMax = max(secondMax, val);
            }
        }
        return 1LL * firstMax * secondMax * 100000;
    }
};