class Solution {
public:
    typedef long long ll;

    struct Node {
        ll cnt;
        ll sum;
    };

    string s;
    Node memo[20][11][11][2];
    bool vis[20][11][11][2];

    Node dfs(int pos, int prev1, int prev2,
             bool started, bool tight) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][prev1][prev2][started])
            return memo[pos][prev1][prev2][started];

        int limit = tight ? s[pos] - '0' : 9;

        Node ans = {0, 0};

        for (int d = 0; d <= limit; d++) {

            bool nStarted = started || (d != 0);

            int np1 = prev1;
            int np2 = prev2;

            int add = 0;

            if (!nStarted) {
                Node child =
                    dfs(pos + 1, 10, 10, false,
                        tight && d == limit);

                ans.cnt += child.cnt;
                ans.sum += child.sum;
                continue;
            }

            if (!started) {
                Node child =
                    dfs(pos + 1, d, 10, true,
                        tight && d == limit);

                ans.cnt += child.cnt;
                ans.sum += child.sum;
            }
            else if (prev2 == 10) {
                Node child =
                    dfs(pos + 1, d, prev1, true,
                        tight && d == limit);

                ans.cnt += child.cnt;
                ans.sum += child.sum;
            }
            else {

                if ((prev1 > prev2 && prev1 > d) ||
                    (prev1 < prev2 && prev1 < d))
                    add = 1;

                Node child =
                    dfs(pos + 1, d, prev1, true,
                        tight && d == limit);

                ans.cnt += child.cnt;
                ans.sum += child.sum + child.cnt * add;
            }
        }

        if (!tight) {
            vis[pos][prev1][prev2][started] = true;
            memo[pos][prev1][prev2][started] = ans;
        }

        return ans;
    }

    long long solve(long long x) {
        if (x <= 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, false, true).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};