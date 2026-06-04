class Solution {
public:
    int getWaviness(int num) {
        string s = to_string(num);
        int n = s.size();

        if (n < 3) return 0;

        int cnt = 0;

        for (int i = 1; i < n - 1; i++) {
            if (s[i] > s[i - 1] && s[i] > s[i + 1])
                cnt++;
            else if (s[i] < s[i - 1] && s[i] < s[i + 1])
                cnt++;
        }

        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int i = num1; i <= num2; i++) {
            ans += getWaviness(i);
        }

        return ans;
    }
};