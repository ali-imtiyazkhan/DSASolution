class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);     // globally processed
        int ans = -1;

        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;

            int current = i;
            unordered_map<int, int> dist;   // dist[node] = step index in the current path
            int step = 0;

            // follow the chain as long as current is valid and not globally visited
            while(current != -1 && !visited[current]) {
                if(dist.count(current)) {
                    // cycle found
                    ans = max(ans, step - dist[current]);
                    break;
                }

                dist[current] = step;
                step++;
                current = edges[current];
            }

            // mark everything in this chain as globally visited
            for (auto &pr : dist) {
                visited[pr.first] = true;
            }
        }

        return ans;
    }
};
