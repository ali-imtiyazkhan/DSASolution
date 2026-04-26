class Solution {
public:
    int m, n;
    vector<vector<int>> visited;
    
    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid) {
        visited[x][y] = 1;
        
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        for(auto &d : dirs) {
            int nx = x + d.first;
            int ny = y + d.second;
            
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(grid[nx][ny] != grid[x][y]) continue;
            
            if(!visited[nx][ny]) {
                if(dfs(nx, ny, x, y, grid)) return true;
            }
            else if(nx != px || ny != py) {
                return true;
            }
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        visited.assign(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    if(dfs(i, j, -1, -1, grid)) return true;
                }
            }
        }
        
        return false;
    }
};