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
public:
    long long totalSum(TreeNode* root) {
        if (!root)
            return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    long long best = 0;
    long long dfs(TreeNode* root, long long total) {
        if (!root)
            return 0;

        long long left = dfs(root->left, total);
        long long right = dfs(root->right, total);

        if (root->left) {
            long long part1 = left;
            long long part2 = total - left;
            best = max(best, part1 * part2);
        }

        if (root->right) {
            long long part1 = right;
            long long part2 = total - right;
            best = max(best, part1 * part2);
        }

        return root->val + left + right;
    }

    int maxProduct(TreeNode* root) {
        long long total = totalSum(root);

        dfs(root, total);
        return best % 1000000007;
    }
};