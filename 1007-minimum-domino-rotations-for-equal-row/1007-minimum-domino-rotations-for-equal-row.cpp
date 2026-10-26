class Solution {
    int getRotation(vector<int> & tops, vector<int> &bottoms, int tar){
        int r_top = 0;
        int r_bottom = 0;
        for(int i = 0; i< tops.size(); i++){
            if(tops[i] != tar && bottoms[i] != tar){
                return INT_MAX;
            }
            if(tops[i] != tar) r_top++;
            if(bottoms[i] != tar) r_bottom++;
        }
        return min(r_top, r_bottom);
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = getRotation(tops, bottoms, tops[0]);
        if(tops[0] != bottoms[0]){
            res = min(res, getRotation(tops, bottoms, bottoms[0]));
        }
        return res == INT_MAX ? -1 : res;
    }
};