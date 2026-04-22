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
    int MAXDEPTH;
    void findMaxDepth(TreeNode* node, int currCount){
        if(!node){
            MAXDEPTH = max(MAXDEPTH, currCount);
            return;
        }
        findMaxDepth(node->left, currCount+1);
        findMaxDepth(node->right, currCount+1);
    }
public:
    int maxDepth(TreeNode* root) {
        MAXDEPTH = 0;
        findMaxDepth(root, 0);
        return MAXDEPTH;
    }
};
