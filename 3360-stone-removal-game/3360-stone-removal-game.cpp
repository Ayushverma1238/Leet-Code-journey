class Solution {
public:
    bool canAliceWin(int n) {
        bool turn = true;
        int count = 10;
        while(n > 0){
            if(count > n){
                break;
            }
            n-= count;
            count--;
            turn = !turn;
        }
        return !turn;
    }
};