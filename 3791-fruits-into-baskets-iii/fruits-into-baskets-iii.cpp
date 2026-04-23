class Solution {
public:
    vector<int> seg;
    int n;

    void build(vector<int>& baskets, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = baskets[l];
            return;
        }
        int mid = (l + r) / 2;
        build(baskets, 2*idx+1, l, mid);
        build(baskets, 2*idx+2, mid+1, r);
        seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
    }

    int query(int idx, int l, int r, int val) {
        if (seg[idx] < val) return -1; 

        if (l == r) return l;

        int mid = (l + r) / 2;

        if (seg[2*idx+1] >= val)
            return query(2*idx+1, l, mid, val);
        else
            return query(2*idx+2, mid+1, r, val);
    }

    void update(int idx, int l, int r, int pos) {
        if (l == r) {
            seg[idx] = -1;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2*idx+1, l, mid, pos);
        else
            update(2*idx+2, mid+1, r, pos);

        seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        n = baskets.size();
        seg.resize(4*n);

        build(baskets, 0, 0, n-1);

        int unplaced = 0;

        for (int fruit : fruits) {
            int pos = query(0, 0, n-1, fruit);

            if (pos == -1) {
                unplaced++;
            } else {
                update(0, 0, n-1, pos);
            }
        }

        return unplaced;
    }
};