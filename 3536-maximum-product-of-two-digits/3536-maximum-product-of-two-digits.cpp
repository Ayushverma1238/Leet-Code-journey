class Solution {
public:
    int maxProduct(int n) {
        vector<int> freq(10,0);
        while(n != 0){
            int rem = n % 10;
            freq[rem]++;
            n /= 10;
        }
        int ans =1;
        int count= 0;
        for(int i = 9; i >= 0;i--){
            if(freq[i] > 1 && ans == 1){
                return i *i;
            }else if(freq[i] > 0){
                count++;
                ans *= i;
                if(count == 2)
                    return ans;
            }
        }
        return ans;

    }
};