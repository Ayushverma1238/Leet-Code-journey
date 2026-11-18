class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff = 0;
        string diff1= "";
        string diff2= "";
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                diff++;
                diff1 += s1[i];
                diff2 += s2[i];
            }
        }
        if(diff > 2 || diff == 1){
            return false;
        }
        if(diff == 0){
            return true;
        }
        sort(diff1.begin(), diff1.end());
        sort(diff2.begin(), diff2.end());
        return diff1[0] == diff2[0] && diff1[1] == diff2[1];
    }
};