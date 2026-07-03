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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
        if(root==nullptr){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            vector<TreeNode*>level;
            int s = q.size();
            for(int i = 0;i<s;i++){
                TreeNode* top = q.front();
                q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
                level.push_back(top);

            }
            ans.push_back(level[level.size()-1]->val);
        }
        return ans;
    }
};
