class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int i = 0, j = tokens.size() - 1;
        sort(tokens.begin(), tokens.end());
        while (i <= j) {
            if (tokens[i] <= power) {
                score++;
                power -= tokens[i];
                i++;
            } else if (j != i && score > 0) {
                // if (j - i > 1) {

                score--;
                power += tokens[j];
                j--;

            } else
                break;
        }
        return (score < 0) ? 0 : score;
    }
};