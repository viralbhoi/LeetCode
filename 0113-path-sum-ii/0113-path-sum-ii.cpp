/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode* root, int ts, int s, vector<vector<int>>& ans,
               vector<int> curr) {
        if (!root) {
            return;
        }

        s += root->val;
        curr.push_back(root->val);

        if (!root->left && !root->right) {
            if (ts == s) {
                ans.push_back(curr);
            }
            return;
        }

        solve(root->left, ts, s, ans, curr);
        solve(root->right, ts, s, ans, curr);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;

        if (!root) {
            return ans;
        }

        solve(root,targetSum, 0, ans, {});

        return ans;
    }
};