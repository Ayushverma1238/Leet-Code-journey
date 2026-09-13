class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> c1, c2;
        for(int i = 0; i< n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1) c1.push_back({i, j});
                if(img2[i][j] == 1) c2.push_back({i, j});
            }
        }

        unordered_map<int, int> freq;
        int ans = 0;
        for(auto [r, c] : c1){
            for(auto [r2, c2] : c2){
                int dr = r - r2;
                int dc= c - c2;
                int key = (dr + 100) * 100 + dc + 100;
                freq[key]++;
                ans = max(ans, freq[key]);
            }
        }
        return ans;
    }
};