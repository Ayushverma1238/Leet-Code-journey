class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        int n1 = s.size(), n2  = t.size();
        while(i < n1 && j < n2){
            if(s[i] == t[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return (n2 - j);
    }
};