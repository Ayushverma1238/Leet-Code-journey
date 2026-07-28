class Solution {
public:
    string smallestPalindrome(string s) {
        int mid = s.size()/2;
        string half = s.substr(0, mid);
        string x = "";
        if(s.size() % 2 != 0){
            x += s[mid];
        }
        sort(half.begin(), half.end());
        string ans= half + x;
        reverse(half.begin(), half.end());
        return ans + half;
    }
};