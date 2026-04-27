class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<int, vector<pair<int,int>>> dirs = {
            {1, {{0,-1}, {0,1}}},     // left, right
            {2, {{-1,0}, {1,0}}},     // up, down
            {3, {{0,-1}, {1,0}}},     // left, down
            {4, {{0,1}, {1,0}}},      // right, down
            {5, {{0,-1}, {-1,0}}},    // left, up
            {6, {{0,1}, {-1,0}}}      // right, up
        };

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({0,0});
        visited[0][0] = true;

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

        if(r == m-1 && c == n-1) return true;

            for(auto [dr, dc] : dirs[grid[r][c]]) {
                int nr = r + dr;
                int nc = c + dc;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {

                    for(auto [bdr, bdc] : dirs[grid[nr][nc]]) {
                        if(dr + bdr == 0 && dc + bdc == 0) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                            break;
                        }
                    }
                }
            }
        }

        return false;
    }
};