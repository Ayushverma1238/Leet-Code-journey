class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        if(n2> n1) return {};

        vector<int> freq1(26,0), freq2(26,0);
        for(int i =0; i< n2; i++){
            freq1[s[i]-'a']++;
            freq2[p[i] -'a']++;
        }
        vector<int> ans;
        if(freq1 == freq2) ans.push_back(0);
        for(int i = n2; i< n1; i++){
            freq1[s[i]-'a']++;
            freq1[s[i-n2]-'a']--;
            if(freq1 == freq2){
                ans.push_back(i-n2+1);
            }
        }
        return ans;
    }
};