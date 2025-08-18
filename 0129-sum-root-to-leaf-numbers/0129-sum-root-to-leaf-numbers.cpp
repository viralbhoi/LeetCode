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
    void dfs(TreeNode* root, string temp, int& sum) {
        if (!root) {
            return;
        }

        temp += to_string(root->val);

        if (root->right) {
            dfs(root->right, temp, sum);
        }

        if (root->left) {
            dfs(root->left, temp, sum);
        }

        if (!root->left && !root->right) {
            sum += stoi(temp);
        }
    }

public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;

        if (!root) {
            return ans;
        }
        dfs(root, "", ans);

        return ans;
    }
};