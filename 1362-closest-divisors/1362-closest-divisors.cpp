class Solution {
    int minDiff = INT_MAX;
    vector<int>ans;
    void getDivisor (int n){
        for(int i = 1;i * i <= n; i++){
            if(n % i == 0){
                int div = n / i;
                if(minDiff > (abs(div - i))){
                    minDiff = abs(div -i);
                    ans = {i, div};
                }
                
            }
        }

    }
public:
    vector<int> closestDivisors(int num) {
        getDivisor(num+1);
        getDivisor(num + 2);
        return ans;
    }
};