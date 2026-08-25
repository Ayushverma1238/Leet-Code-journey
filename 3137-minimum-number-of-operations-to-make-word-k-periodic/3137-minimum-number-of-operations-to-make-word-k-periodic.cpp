class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int>mp;
        int cnt = 0;
        string aux = "";
        for(auto c : word){
            if(cnt < k){
                aux += c;
            }else{
                mp[aux]++;
                aux = c;
                cnt = 0;
            }
            cnt++;
        }
        mp[aux]++;
        int maxVal = INT_MIN;
        int sum =0;
        for(auto it : mp){
            maxVal = max(maxVal, it.second);
            sum += it.second;
        }
        return sum - maxVal;
    }
};