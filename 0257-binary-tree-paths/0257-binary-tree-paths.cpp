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
    void dfs(TreeNode* root, vector<string>& ans, string curr) {
        curr += to_string(root->val);

        if (root->right)
            dfs(root->right, ans, curr + "->");
        if (root->left)
            dfs(root->left, ans, curr + "->");
        if (!root->right && !root->left)
            ans.push_back(curr);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        if (root) {
            dfs(root, ans, "");
        }

        return ans;
    }
};