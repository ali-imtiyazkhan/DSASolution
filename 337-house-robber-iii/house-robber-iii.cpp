class Solution {
public:
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // If we rob this node, we cannot rob children
        int rob = root->val + left.first + right.first;

        // If we don't rob this node, we take max of rob/notRob from children
        int notRob = max(left.first, left.second) + max(right.first, right.second);

        return {notRob, rob};
    }

    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};
