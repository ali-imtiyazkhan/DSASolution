class Solution {
public:
    
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            for (int d = 2; d * d <= x; d++) {
                if (x % d == 0) {

                    if (isPrime(d))
                        mp[d].push_back(i);

                    while (x % d == 0)
                        x /= d;
                }
            }

            if (x > 1)
                mp[x].push_back(i);
        }

        vector<int> dist(n, -1);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        unordered_set<int> usedPrime;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1)
                return dist[i];

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            int val = nums[i];

            if (isPrime(val) && !usedPrime.count(val)) {

                usedPrime.insert(val);

                for (int nxt : mp[val]) {
                    if (nxt != i && dist[nxt] == -1) {
                        dist[nxt] = dist[i] + 1;
                        q.push(nxt);
                    }
                }
            }
        }

        return -1;
    }
};