class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        int maxElem= nums[0];
        int minElem= nums[0];
        for(int n : nums){
            mp[n]++;
            maxElem = max(maxElem, n);
            minElem = min(minElem, n);
        }
        for(int i = minElem; i< maxElem;i++){
            if(mp.find(i) == mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};