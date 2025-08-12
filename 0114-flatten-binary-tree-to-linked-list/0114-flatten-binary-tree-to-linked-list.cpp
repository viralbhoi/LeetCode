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
    void preOrder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) {
            return;
        }

        nodes.push_back(root);
        preOrder(root->left, nodes);
        preOrder(root->right, nodes);
    }

public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> nd;

        preOrder(root, nd);
        for (int i = 1; i < nd.size(); i++) {
            root->right = nd[i];
            root->left = NULL;
            root = root->right;
        }
    }
};