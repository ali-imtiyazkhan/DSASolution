class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;

        int minVal = root->val;
        long ans = LONG_MAX;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;

            if (node->val > minVal) {
                ans = min(ans, (long)node->val);
                return;
            }

            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);

        return (ans == LONG_MAX) ? -1 : ans;
    }
};