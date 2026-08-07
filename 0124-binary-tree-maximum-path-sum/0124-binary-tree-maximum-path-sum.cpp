/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxSum = INT_MIN;
    int posOrder(TreeNode * root){
        if(root == nullptr){
            return 0;
        }

        int left = max(0, posOrder(root->left));
        int right = max(0, posOrder(root->right));

        int currGain = root->val + left + right;
        maxSum = max(maxSum, currGain);
        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        posOrder(root);
        return maxSum;
    }
};