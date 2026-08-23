class Solution {
public:
    bool sumGame(string num) {
        int sumDiff = 0, qDiff =0;
        int n = num.size();
        for(int i = 0; i< n/2; i++){
            if(num[i] =='?') qDiff++;
            else sumDiff += num[i]-'0';
        }

        for(int i = n/2;i  < n; i++){
            if(num[i] == '?') qDiff--;
            else sumDiff -= num[i]-'0';
        }
        return sumDiff != (double)qDiff * (-4.5);
       
    }
};