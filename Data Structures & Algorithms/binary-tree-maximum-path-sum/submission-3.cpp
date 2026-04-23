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
private:
    int findMaxSum(TreeNode* node, int& ans){
        if(!node) return INT_MIN;
        int leftMaxSum = findMaxSum(node->left, ans);
        int rightMaxSum = findMaxSum(node->right, ans);
        int sum1 = node->val + max(0, leftMaxSum) + max(0, rightMaxSum);
        ans = max(ans, max(sum1, max(leftMaxSum, rightMaxSum)));
        return node->val + max(0, max(leftMaxSum, rightMaxSum));
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int res = findMaxSum(root, ans);
        return max(ans, res);
    }
};
