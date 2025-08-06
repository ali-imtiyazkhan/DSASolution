class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Find the position to fill the value
                int index = leftToRight ? i : (levelSize - 1 - i);
                level[index] = node->val;

                // Add child nodes for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // After processing current level
            result.push_back(level);
            leftToRight = !leftToRight; // flip direction
        }

        return result;
    }
};
