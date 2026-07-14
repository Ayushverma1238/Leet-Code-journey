class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int ans =0;
        for(int i = 0; i< n; i++){
            int gc = nums[i];
          
            for(int j = i; j< n; j++){
                gc = gcd(gc, nums[j]);
                if(gc < k)
                    break;
                else if(gc == k)
                    ans++;
            }
        }
        return ans;
    }
};