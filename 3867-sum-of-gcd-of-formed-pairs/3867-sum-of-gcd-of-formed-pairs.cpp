class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> aux (n, 0);
        int maxVal = nums[0];
        for(int i =0; i< n; i++){
            maxVal = max(maxVal, nums[i]);
            aux[i] = gcd(nums[i], maxVal);
        }
        sort(aux.begin(), aux.end());
        int i = 0, j = n-1;
        long long ans = 0;
        while(i <j){
            ans += gcd(aux[i++], aux[j--]);
        }
        return ans;
    }
};