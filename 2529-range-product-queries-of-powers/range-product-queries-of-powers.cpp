class Solution {
public:
    const long long MOD = 1e9 + 7;

    // fast exponentiation (a^b % MOD)
    long long modPow(long long a, long long b, long long mod) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        
        // extract powers of 2 from binary representation
        for (int i = 0; n > 0; i++) {
            if (n & 1) powers.push_back(1 << i);
            n >>= 1;
        }
        
        // compute prefix product
        int m = powers.size();
        vector<long long> prefix(m);
        prefix[0] = powers[0];
        for (int i = 1; i < m; i++) {
            prefix[i] = (prefix[i - 1] * powers[i]) % MOD;
        }

        // answer queries
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long res = prefix[r];
            if (l > 0) {
                // divide by prefix[l-1] using modular inverse
                res = (res * modPow(prefix[l - 1], MOD - 2, MOD)) % MOD;
            }
            ans.push_back((int)res);
        }
        return ans;
    }
};
