class Solution {
public:
   string convert(string s, int numRow) {
    if (numRow == 1 || s.length() <= numRow) return s;

    vector<string> rows(min(static_cast<int>(s.length()), numRow));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[curRow] += c;
        // Reverse direction when reaching top or bottom boundary
        if (curRow == 0 || curRow == numRow - 1) {
            goingDown = !goingDown;
        }
        curRow += goingDown ? 1 : -1;
    }

    string result;
    for (const string& row : rows) {
        result += row;
    }
    return result;
}
};