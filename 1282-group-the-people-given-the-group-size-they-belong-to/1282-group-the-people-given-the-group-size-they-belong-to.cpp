class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans;
        for(int i =0; i < groupSizes.size(); i++){
            mp[groupSizes[i]].push_back(i);
            if(groupSizes[i] == mp[groupSizes[i]].size()){
                ans.push_back(mp[groupSizes[i]]);
                mp.erase(groupSizes[i]);
            }
        }
        return ans;
    }
};