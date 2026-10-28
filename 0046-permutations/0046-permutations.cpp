class Solution {
    int n;
    vector<vector<int>> ans;
    void solve(vector<int> & nums, vector<bool> & used, vector<int>& aux){
        if(aux.size() == n){
            ans.push_back(aux);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(used[i])
                continue;
            used[i] = true;
            aux.push_back(nums[i]);
            solve(nums, used, aux);
            aux.pop_back();
            used[i] = false;
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> aux;
        vector<bool> used(n, false);
        solve(nums, used, aux);
        return ans;
    }
};