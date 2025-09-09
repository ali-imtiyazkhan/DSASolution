class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1'000'000'007;
        vector<long long> dp(n + 1, 0);  // dp[i] = number of people who learn secret on day i
        dp[1] = 1;

        long long shareSum = 0;  // running window sum for active sharers

        for (int day = 2; day <= n; ++day) {
            // person who learned on (day - delay) starts sharing today
            int enter = day - delay;
            if (enter >= 1) {
                shareSum = (shareSum + dp[enter]) % MOD;
            }

            // person who learned on (day - forget) forgets today
            int leave = day - forget;
            if (leave >= 1) {
                shareSum = (shareSum - dp[leave]) % MOD;
                if (shareSum < 0) shareSum += MOD;
            }

            dp[day] = shareSum % MOD;
        }

        // final count = people who still remember secret on day n
        long long ans = 0;
        for (int j = max(1, n - forget + 1); j <= n; ++j) {
            ans = (ans + dp[j]) % MOD;
        }

        return (int)ans;
    }
};
