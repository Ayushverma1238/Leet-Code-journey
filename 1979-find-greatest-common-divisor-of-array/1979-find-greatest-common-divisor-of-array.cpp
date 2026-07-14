class Solution {
    int gcd(int n1, int n2){
        int ans = 1;
        for(int i= 2; i<= min(n1, n2); i++){
            if(n1 % i ==0 && n2 % i == 0)
            ans = i;
        }
        return ans;
    }
public:
    int findGCD(vector<int>& nums) {
        int minVal = nums[0];
        int maxVal = nums[0];
        for(auto n : nums){
            minVal = min(minVal, n);
            maxVal = max(maxVal, n);
        }

        return gcd(minVal, maxVal);
    }
};