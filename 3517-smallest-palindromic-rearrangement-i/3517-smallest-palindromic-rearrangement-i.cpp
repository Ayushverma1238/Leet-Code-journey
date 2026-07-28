class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(), s.end());
        string start = "", end = "";
        int i = 0;
        int n = s.size();
        string midd = "";
        while(i < n){
            if(s[i] == s[i+1]){
                start += s[i];
                end += s[i];
                i+=2;
            }else {
                midd += s[i];
                i++;
            }
        }
        reverse(end.begin(), end.end());
        return start +  midd + end;
    
    }
};