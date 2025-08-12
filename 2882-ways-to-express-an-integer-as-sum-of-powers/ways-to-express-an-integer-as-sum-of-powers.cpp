class Solution {
public:
  int numberOfWays(int n, int x) {
    const int MOD = 1e9 + 7;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    int power;
    for (int a = 1; (power = pow(a, x)) <= n; ++a) {
      for (int i = n; i >= power; --i) {
        dp[i] = (dp[i] + dp[i - power]) % MOD;
      }
    }
    return dp[n];
  }
};
