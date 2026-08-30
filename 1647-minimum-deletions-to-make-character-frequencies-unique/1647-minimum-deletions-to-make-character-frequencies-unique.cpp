class Solution {
public:
    int minDeletions(string s) {
        vector<int> mp(26, 0);
        unordered_set<int> st;
        for(auto c : s){
            mp[c-'a']++;
        }
        int count = 0;
        sort(mp.rbegin(), mp.rend());
        for(auto it : mp){
            // if(it == 0) continue;
            while(st.find(it) !=st.end()){
                count++;
                it--;
            }
            if(it != 0)
                st.insert(it);
        }

        return count;

    }
};