class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pref(n +1, 0);
        for(int i= 0; i< n; i++){
            pref[i+1] = pref[i]+ stoneValue[i];
        }
        vector<vector<int>>memo(n, vector<int> (n, -1));
        function<int(int, int)>solve = [&](int left, int right){
            if(left >= right){
                return 0;
            }
            if(memo[left][right] != -1) return memo[left][right];
            int maxScore = 0;
            for(int i= left; i < right; i++){
                int leftSum = pref[i+1] - pref[left];
                int rightSum = pref[right+1] - pref[i + 1];
                if(leftSum < rightSum){
                    maxScore = max(maxScore, leftSum + solve(left, i));
                }else if(leftSum > rightSum){
                    maxScore = max(maxScore, rightSum + solve(i+1, right));
                }else{
                    maxScore = max(maxScore, leftSum + max(solve(left, i), solve(i + 1, right)));
                }
            }
            return memo[left][right] = maxScore;
        };
        return solve(0,n-1);
    }
};