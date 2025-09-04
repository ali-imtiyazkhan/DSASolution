class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dx = abs(x-z);
        int dy = abs(y-z);
        if(dx == dy) return 0;

      return dx < dy ? 1 : 2;
    }
};