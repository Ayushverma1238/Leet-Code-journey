class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto n : nums){
            mp[n]++;
        }
        int i = 0;
        for(i = 1;i<= nums.size(); i++){
            if(mp.find(i * k) == mp.end()){
                return i * k;
            }
        }
        return k * i;
    }
};