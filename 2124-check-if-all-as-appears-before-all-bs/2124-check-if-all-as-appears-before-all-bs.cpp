class Solution {
public:
    bool checkString(string s) {
        bool isb = false;
        for(auto c : s){
            if(c == 'a'){
                if(isb)
                    return false;
            }
            if(c == 'b')
                isb = true;
        }   
        return true;
    }
};