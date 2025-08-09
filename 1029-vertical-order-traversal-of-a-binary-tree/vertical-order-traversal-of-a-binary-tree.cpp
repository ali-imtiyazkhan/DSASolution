class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // col -> list of {row, value}
        map<int, vector<pair<int, int>>> cols;
        
        // Queue for BFS: node, row, col
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            
            int row = pos.first, col = pos.second;
            cols[col].push_back({row, node->val});
            
            if (node->left)  q.push({node->left,  {row + 1, col - 1}});
            if (node->right) q.push({node->right, {row + 1, col + 1}});
        }
        
        vector<vector<int>> result;
        
        for (auto &entry : cols) {
            auto &vec = entry.second;
            // Sort by row first, then value
            sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
                if (a.first == b.first) return a.second < b.second;
                return a.first < b.first;
            });
            
            vector<int> colVals;
            for (auto &p : vec) colVals.push_back(p.second);
            result.push_back(colVals);
        }
        
        return result;
    }
};
