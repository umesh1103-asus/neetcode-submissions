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
    int maxDiameter;
    int subTreeLength(TreeNode* node){
        if(!node) return 0;
        int leftTreeLength = subTreeLength(node->left);
        int rightTreeLength = subTreeLength(node->right);

        maxDiameter = max(maxDiameter, leftTreeLength + rightTreeLength);
        return max(leftTreeLength, rightTreeLength) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        subTreeLength(root);
        return maxDiameter;
    }
};
