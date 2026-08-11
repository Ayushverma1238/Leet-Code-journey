class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for(auto n : nums){
            sum += n;
        }

        if(sum == goal){
            return 0;
        }

        long long target = abs(goal - sum);
        int ans = 0;
        ans += (target / limit);
        if(target % limit > 0){
            ans++;
        }
        return ans;
    }
};