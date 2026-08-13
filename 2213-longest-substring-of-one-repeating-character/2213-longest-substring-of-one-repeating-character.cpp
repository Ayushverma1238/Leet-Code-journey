#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int mx;
    int prefLen;
    int suffLen;
    char leftChar;
    char rightChar;

    Node() : mx(0), prefLen(0), suffLen(0), leftChar(' '), rightChar(' ') {}
};

class Solution {
    int n;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right, int leftSize, int rightSize) {
        Node res;
        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;
        res.mx = max(left.mx, right.mx);

        if (left.rightChar == right.leftChar) {
            res.mx = max(res.mx, left.suffLen + right.prefLen);
        }

        if (left.prefLen == leftSize && left.rightChar == right.leftChar) {
            res.prefLen = left.prefLen + right.prefLen;
        } else {
            res.prefLen = left.prefLen;
        }

        if (right.suffLen == rightSize && left.rightChar == right.leftChar) {
            res.suffLen = right.suffLen + left.suffLen;
        } else {
            res.suffLen = right.suffLen;
        }

        return res;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node].mx = 1;
            tree[node].prefLen = 1;
            tree[node].suffLen = 1;
            tree[node].leftChar = s[start];
            tree[node].rightChar = s[start];
            return;
        }
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        build(s, leftChild, start, mid);
        build(s, rightChild, mid + 1, end);

        tree[node] = merge(tree[leftChild], tree[rightChild], mid - start + 1, end - mid);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node].leftChar = ch;
            tree[node].rightChar = ch;
            return;
        }
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        if (idx <= mid) {
            update(leftChild, start, mid, idx, ch);
        } else {
            update(rightChild, mid + 1, end, idx, ch);
        }

        tree[node] = merge(tree[leftChild], tree[rightChild], mid - start + 1, end - mid);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.length();
        tree.resize(4 * n);

        build(s, 0, 0, n - 1);

        int k = queryIndices.size();
        vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            update(0, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[0].mx; 
        }

        return ans;
    }
};