class Solution {
public:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (!node) return 0;

        int leftGain = max(0, maxGain(node->left));
        int rightGain = max(0, maxGain(node->right));

        int localMax = node->val + leftGain + rightGain;

        maxSum = max(maxSum, localMax);

        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
