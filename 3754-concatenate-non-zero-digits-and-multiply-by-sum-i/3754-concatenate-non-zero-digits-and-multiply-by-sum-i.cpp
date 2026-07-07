class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        string s = to_string(n);
        string newS = "";
        long long x = 0;
        for(auto c : s){
            if(c != '0'){
                newS += c;
                x += (c-'0');
            }
        }
        long long ans = stoi(newS);
        return 1LL * ans * x;
    }
};