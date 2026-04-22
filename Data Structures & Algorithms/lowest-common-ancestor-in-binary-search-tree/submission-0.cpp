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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val1 = max(p->val, q->val);
        int val2 = min(p->val, q->val);
        int rootVal = root->val;
        if(rootVal == val1 || rootVal == val2) return root;
        if(rootVal>val1) return lowestCommonAncestor(root->left, p, q);
        else if(rootVal<val2) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
