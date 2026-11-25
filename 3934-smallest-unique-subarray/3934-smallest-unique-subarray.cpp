class Solution {
    const long long mod1 = 1e9 + 7;
    const long long mod2 = 1e9 + 9;
    const long long base = 100003;
    bool check(vector<int> & nums, int len){
        int n = nums.size();
        if(len > n){
            return false;
        }
        long long power1 = 1, power2 = 1;
        for(auto i = 0; i < len; i++){
            power1 = (power1 * base) % mod1;
            power2 = (power2 * base) % mod2;
        }
        map<pair<long long, long long>, int> mp;
        long long currHash1 = 0;
        long long currHash2 = 0;

        for (int i = 0; i < len; i++) {
            currHash1 = (currHash1 * base + nums[i]) % mod1;
            currHash2 = (currHash2 * base + nums[i]) % mod2;
        }
        mp[{currHash1, currHash2}]++;
        for (int i = len; i < n; i++) {
            currHash1 = ((currHash1 * base)% mod1 + nums[i] -
                         (nums[i - len] * power1) % mod1 + mod1) % mod1;
            currHash2 = ((currHash2 * base) % mod2 + nums[i] -
                         (nums[i - len] * power2) % mod2 + mod2) % mod2;

            mp[{currHash1, currHash2}]++;
        }

        for (auto const& [hash_pair, count] : mp) {
            if (count == 1)
                return true;
        }
        return false;
    }
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int low = 0, high = nums.size();
        int ans = nums.size();
        while(low <= high){
            int mid = (low + high)/2;
            if(check(nums, mid)){
                ans= mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};