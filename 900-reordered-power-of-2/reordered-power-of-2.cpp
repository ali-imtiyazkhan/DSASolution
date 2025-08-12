class Solution {
public:
   
    int digitSignature(int x) {
        int sig = 0;
        while (x > 0) {
            int digit = x % 10;
            sig += pow(10, digit);
            x /= 10;
        }
        return sig;
    }

    bool reorderedPowerOf2(int n) {
        int targetSig = digitSignature(n);
        for (int i = 0; i < 31; ++i) { // 2^30 < 1e9
            if (digitSignature(1 << i) == targetSig) {
                return true;
            }
        }
        return false;
    }
};
