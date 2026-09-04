class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long> contr(26, 0);
        long long totalSum = 0;
        for(int i = 0; i < s.size(); i++){
            contr[s[i]-'a'] += cost[i];
            totalSum += cost[i];
        }
        long long ans = totalSum;
        for(int i = 0; i< 26; i++){
            ans = min(ans, totalSum - contr[i]);
        }
        return ans;
    }
};