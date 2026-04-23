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
        if(!node) {
            cout <<"yes "<<INT_MIN<<endl;
            return INT_MIN;
        }
        int leftMaxSum = findMaxSum(node->left, ans);
        cout <<"leftmax "<<leftMaxSum<<endl;
        int rightMaxSum = findMaxSum(node->right, ans);
        cout <<"rightmax "<<rightMaxSum<<endl;
        int sum1 = node->val + max(0, leftMaxSum) + max(0, rightMaxSum);
        cout <<"sum "<<sum1<<endl;
        ans = max(ans, max(sum1, max(leftMaxSum, rightMaxSum)));
        cout <<"ans "<<ans<<endl;
        return node->val + max(0, max(leftMaxSum, rightMaxSum));
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int res = findMaxSum(root, ans);
        cout<< "res "<<res<<" ans "<<ans<<endl;
        return max(ans, res);
    }
};
