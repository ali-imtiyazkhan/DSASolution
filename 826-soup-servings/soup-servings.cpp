class Solution {
public:
    double soupServings(int n) {
        // scale down by 25 and ceil
        int s = (n + 24) / 25;
        // cutoff: for large n result ~ 1.0
        if (s >= 200) return 1.0;
        memo.assign(s + 1, vector<double>(s + 1, -1.0));
        return dp(s, s);
    }

private:
    vector<vector<double>> memo;

    double dp(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5; // both empty simultaneously
        if (a <= 0) return 1.0;           // A empty first
        if (b <= 0) return 0.0;           // B empty first
        if (memo[a][b] >= 0) return memo[a][b];

        double res = 0.0;
        // four serving options (units of 25): (4,0),(3,1),(2,2),(1,3)
        res += 0.25 * dp(a - 4, b);     // serve 100 from A, 0 from B
        res += 0.25 * dp(a - 3, b - 1); // serve 75 A, 25 B
        res += 0.25 * dp(a - 2, b - 2); // serve 50 A, 50 B
        res += 0.25 * dp(a - 1, b - 3); // serve 25 A, 75 B

        memo[a][b] = res;
        return res;
    }
};
