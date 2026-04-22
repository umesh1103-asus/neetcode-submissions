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
    void ingestByLevel(vector<vector<int>>& res, TreeNode* node, int level){
        if(!node) return;
        if(res.size()<level){
            vector<int> temp = {node->val};
            res.push_back(temp);
        }
        else res[level-1].push_back(node->val);
        ingestByLevel(res, node->left, level+1);
        ingestByLevel(res, node->right, level+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        ingestByLevel(res, root, 1);
        return res;
    }
};
