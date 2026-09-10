/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int ans = 0;
    pair<int, int> postOrder(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};
        auto left = postOrder(root->left);
        auto right = postOrder(root->right);
        int currSum = root->val + left.first + right.first;
        int currCount = 1 + left.second + right.second;
        if (currSum / currCount == root->val)
            ans++;
        return {currSum, currCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return ans;
    }
};