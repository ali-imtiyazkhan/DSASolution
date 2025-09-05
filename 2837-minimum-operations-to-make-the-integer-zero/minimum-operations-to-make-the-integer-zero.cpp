class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long remaining = (long long)num1 - (long long)k * num2;
            if (remaining < k) continue; // can't split into k positive integers

            // Count number of set bits in remaining
            int bits = __builtin_popcountll(remaining);
            if (bits <= k) return k;
        }
        return -1;
    }
};
