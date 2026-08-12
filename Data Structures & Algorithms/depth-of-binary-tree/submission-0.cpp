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
    int ischeck(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = ischeck(root->left);
        int right = ischeck(root->right);

        return 1 + max(left, right);
    }

    int maxDepth(TreeNode* root) {
        int ans = ischeck(root);
        return ans;
    }
};