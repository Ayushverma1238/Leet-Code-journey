class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, 
    vector<vector<int>>& queries) {
        int cmpID = 1;
        vector<int> pref(n, 0);
        pref[0] = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i-1] <= maxDiff){
                pref[i] = pref[i-1];
            }else{
                pref[i] = ++cmpID;
            }

        }
        int m = queries.size();
        vector<bool> ans(m, false);
        for(int i = 0; i< m;i++){
            vector<int> q = queries[i];
            if(pref[q[0]] == pref[q[1]]){
                ans[i]=true;
            }else{
                ans[i] =false;
            }
        }
        return ans;
    
    }
};