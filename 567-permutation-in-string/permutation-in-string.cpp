class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int n = s2.size();
        int m = s1.size();

        vector<int> freq1(26, 0);
        vector<int> window(26, 0);

        for (char c : s1) {
            freq1[c - 'a']++;
        }

        for (int i = 0; i < m; i++) {
            window[s2[i] - 'a']++;
        }

        if (window == freq1) return true;

        for (int i = m; i < n; i++) {
            window[s2[i - m] - 'a']--;
            window[s2[i] - 'a']++;

            if (window == freq1)
                return true;
        }

        return false;
    }
};
