class Solution {
public:
    struct SegTree {
        int n;
        vector<int> tree;

        SegTree(int n) : n(n) {
            tree.resize(4 * n + 5, 0);
        }

        void update(int idx, int val, int node, int l, int r) {
            if (l == r) {
                tree[node] = val;
                return;
            }

            int mid = (l + r) / 2;

            if (idx <= mid)
                update(idx, val, 2 * node, l, mid);
            else
                update(idx, val, 2 * node + 1, mid + 1, r);

            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }

        void update(int idx, int val) {
            update(idx, val, 1, 0, n);
        }

        int query(int L, int R, int node, int l, int r) {
            if (R < l || r < L) return 0;

            if (L <= l && r <= R)
                return tree[node];

            int mid = (l + r) / 2;

            return max(
                query(L, R, 2 * node, l, mid),
                query(L, R, 2 * node + 1, mid + 1, r)
            );
        }

        int query(int l, int r) {
            if (l > r) return 0;
            return query(l, r, 1, 0, n);
        }
    };

    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 0;

        for (auto &q : queries)
            mx = max(mx, q[1]);

        set<int> obstacles;
        obstacles.insert(0);

        for (auto &q : queries) {
            if (q[0] == 1)
                obstacles.insert(q[1]);
        }

        SegTree seg(mx + 2);

        int last = 0;
        for (int x : obstacles) {
            seg.update(x, x - last);
            last = x;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {
            auto &q = queries[i];

            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);
                --it;

                int pre = *it;

                int best = max(
                    seg.query(0, pre),
                    x - pre
                );

                ans.push_back(best >= sz);
            }
            else {
                int x = q[1];

                auto it = obstacles.find(x);

                auto prv = std::prev(it);
                auto nxt = std::next(it);

                if (nxt != obstacles.end()) {
                    seg.update(*nxt, *nxt - *prv);
                }

                obstacles.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};