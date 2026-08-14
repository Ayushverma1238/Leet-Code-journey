class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i = 0, j = 0;
        int n = s.size();
        int ans = 0;
        vector<int> freq(26, 0);
        while(i <= j && j < n){
            freq[s[j]-'a']++;
            if(freq[s[j] -'a'] > 2){
                freq[s[i]-'a']--;
                freq[s[j]-'a']--;
                i++;
            }else{
                ans = max(ans, (j - i + 1));
                j++;
            }
        }
        return ans;
    }
};