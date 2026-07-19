#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIdx(26, 0);
        for (int i = 0; i < s.size(); i++) {
            lastIdx[s[i] - 'a'] = i; // Track last seen position
        }
        
        vector<bool> visited(26, false);
        string ans = ""; // Acts as our monotonic stack
        
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            
            // If the character is already included, skip it
            if (visited[ch - 'a']) continue;
            
            // Pop larger characters from the end of our answer if they appear later
            while (!ans.empty() && ans.back() > ch && lastIdx[ans.back() - 'a'] > i) {
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            
            ans.push_back(ch);
            visited[ch - 'a'] = true;
        }
        
        return ans;
    }
};