class Solution {
public:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (!node) return 0;

        // Only take positive gains
        int leftGain = max(0, maxGain(node->left));
        int rightGain = max(0, maxGain(node->right));

        // Local max path includes both children + node
        int localMax = node->val + leftGain + rightGain;

        // Update global max
        maxSum = max(maxSum, localMax);

        // Return max gain (used for parent path)
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
