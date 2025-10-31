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
    // 0 -> not covered
    // 1-> covered
    // 2-> i have camera;
    int dfs(TreeNode* root, int& ans) {
        if (!root) {
            return 1;
        }

        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);

        if (left == 0 || right == 0) {
            ans++;
            return 2; // either left or right dont have coverage so to cover current node has to be camera;
        }

        if (left == 2 || right == 2) {
            return 1; // since one of child has camera node is already covered no camera
        }

        return 0; // since neither covered nor has camera means not covered so return 0;
    }

public:
    int minCameraCover(TreeNode* root) {

        int ans = 0;

        if (dfs(root, ans) == 0) {
            ans++;
        }

        return ans;
    }
};