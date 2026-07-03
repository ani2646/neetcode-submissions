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
    vector<int> f(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>(2, 0);
        }

        vector<int> left = f(root->left);
        vector<int> right = f(root->right);

        vector<int> option(2, 0);

        // option[0] = rob current node
        option[0] = root->val + left[1] + right[1];

        // option[1] = do not rob current node
        option[1] = max(left[0], left[1]) + max(right[0], right[1]);

        return option;
    }

    int rob(TreeNode* root) {
        vector<int> option = f(root);
        return max(option[0], option[1]);
    }
};