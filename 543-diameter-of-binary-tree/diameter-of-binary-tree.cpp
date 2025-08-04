class Solution {
public:
    int maxDiameter = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = dfs(node->left);
        int rightHeight = dfs(node->right);

        // Update the diameter at this node
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return height of current node
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxDiameter;
    }
};
