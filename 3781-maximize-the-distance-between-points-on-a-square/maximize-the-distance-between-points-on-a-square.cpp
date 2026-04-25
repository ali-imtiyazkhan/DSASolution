class Solution {
public:
    long long getPos(int x, int y, int side) {
        if (y == 0) return x;
        if (x == side) return side + y;
        if (y == side) return 3LL * side - x;
        return 4LL * side - y;
    }

    long long manhattan(pair<int,int>& a, pair<int,int>& b) {
        return abs((long long)a.first - b.first) + abs((long long)a.second - b.second);
    }

    bool can(vector<pair<int,int>>& pts, vector<long long>& pos, int k, long long d, long long side) {
        int n = pts.size();

        vector<pair<int,int>> extPts = pts;
        vector<long long> extPos = pos;

        for (int i = 0; i < n; i++) {
            extPts.push_back(pts[i]);
            extPos.push_back(pos[i] + 4LL * side);
        }

        for (int start = 0; start < n; start++) {
            int count = 1;
            int last = start;
            bool ok = true;

            while (count < k) {

                int lo = last + 1, hi = start + n - 1, next = -1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (extPos[mid] - extPos[last] >= d) {
                        next = mid;
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                }

                if (next == -1) { ok = false; break; }

                if (manhattan(extPts[next], extPts[last]) >= d) {
                
                    count++;
                    last = next;
                } else {

                    last = next;
                }
            }

            if (!ok) continue;

            if (count >= k && manhattan(extPts[last], extPts[start]) >= d) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();

        vector<pair<int,int>> pts;
        vector<long long> pos;

        for (auto& p : points) {
            pts.push_back({p[0], p[1]});
            pos.push_back(getPos(p[0], p[1], side));
        }

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return pos[a] < pos[b];
        });

        vector<pair<int,int>> sortedPts;
        vector<long long> sortedPos;

        for (int i : idx) {
            sortedPts.push_back(pts[i]);
            sortedPos.push_back(pos[i]);
        }

        long long low = 0, high = 2LL * side, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (can(sortedPts, sortedPos, k, mid, side)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};