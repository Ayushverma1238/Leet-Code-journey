class Solution {
    long long calcDis(int x1, int y1, int x2, int y2){
        int x = abs(x1 - x2);
        int y = abs(y1 - y2);
        return (x + y);
    }
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        long long des = calcDis(0,0, target[0], target[1]);

        for(auto gho : ghosts){
            long long tarDis= calcDis(target[0], target[1], gho[0], gho[1]);
            if(des >= tarDis){
                return false;
            }
        }
        return true;
    }
};