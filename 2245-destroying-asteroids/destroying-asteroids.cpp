class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        for (int asteroid : asteroids) {
            if (mass < asteroid) return false;

           
            if (mass <= INT_MAX - asteroid) {
                mass += asteroid;
            } else {
                mass = INT_MAX;
            }
        }

        return true;
    }
};
