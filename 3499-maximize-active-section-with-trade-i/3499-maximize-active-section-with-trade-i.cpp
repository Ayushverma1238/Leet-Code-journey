class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOnes = 0;
        vector<int> zeroLengths;
        
        int n = s.size();
        int i = 0;
        
        while (i < n) {
            if (s[i] == '1') {
                totalOnes++;
                i++;
            } else {
                int len = 0;
                while (i < n && s[i] == '0') {
                    len++;
                    i++;
                }
                zeroLengths.push_back(len);
            }
        }
        
        int maxGain = 0;
        // Check every pair of adjacent '0' segments
        for (size_t k = 1; k < zeroLengths.size(); k++) {
            maxGain = max(maxGain, zeroLengths[k - 1] + zeroLengths[k]);
        }
        
        return totalOnes + maxGain;
    }
};