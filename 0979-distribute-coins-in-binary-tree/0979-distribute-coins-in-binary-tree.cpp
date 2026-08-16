class Solution {
public:
    int moves = 0;

    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int balance = root->val + left + right - 1;

        moves += abs(balance);

        return balance;
    }

    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};