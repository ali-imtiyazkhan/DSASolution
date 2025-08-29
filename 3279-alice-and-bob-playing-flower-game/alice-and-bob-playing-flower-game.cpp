class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddX = (n + 1) / 2;   // number of odd x in [1..n]
        long long evenX = n / 2;        // number of even x in [1..n]
        long long oddY = (m + 1) / 2;   // number of odd y in [1..m]
        long long evenY = m / 2;        // number of even y in [1..m]
        
        // Alice wins if x+y is odd → (odd x + even y) OR (even x + odd y)
        return oddX * evenY + evenX * oddY;
    }
};
