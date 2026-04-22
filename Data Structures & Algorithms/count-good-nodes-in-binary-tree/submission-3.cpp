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
    int COUNT;
    void findGoodNodes(TreeNode* node, int mx){
        if(!node) return;
        if(node->val >= mx) COUNT++;
        findGoodNodes(node->left, max(mx, node->val));
        findGoodNodes(node->right, max(mx, node->val));
    }
public:
    int goodNodes(TreeNode* root) {
        COUNT = 0;
        findGoodNodes(root, -101);
        return COUNT;
    }
};
