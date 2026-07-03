class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for(auto num : nums){
            x ^= num;
        }
        if(x == 0) return true;
        if(x != 0 && n % 2 == 0) return true;
        return false;

    }
};