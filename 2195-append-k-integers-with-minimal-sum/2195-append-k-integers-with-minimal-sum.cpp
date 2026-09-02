class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = (long long) k * (k + 1)/2;
        long long currK = k;
        long long prev = -1;
        for(auto num : nums){
            if(num == prev) continue;
            prev = num;
            if(num <= currK){
                sum -= num;
                currK++;
                sum += currK;
            }else{
                break;
            }
        }
        return sum;
    }
};