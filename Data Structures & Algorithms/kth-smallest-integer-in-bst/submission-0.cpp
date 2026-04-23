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
    void findKthSmallest(TreeNode* node, int&k, int& res){
        if(!node) return;
        if(k==0) return;
        findKthSmallest(node->left, k, res);
        k--;
        if(k==0){
            res = node->val;
            return;
        }
        findKthSmallest(node->right, k, res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        findKthSmallest(root, k, res);
        return res;
    }
};
