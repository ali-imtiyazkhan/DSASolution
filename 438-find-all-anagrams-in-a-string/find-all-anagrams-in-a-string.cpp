class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size() < p.size()) return res;

        vector<int> pCount(26, 0);
        vector<int> window(26, 0);

        for(char c : p) {
            pCount[c - 'a']++;
        }

        int n = s.size();
        int m = p.size();

        for(int i = 0; i < m; i++) {
            window[s[i] - 'a']++;
        }
  
        if(window == pCount) res.push_back(0);

        for(int i = m; i < n; i++) {
            window[s[i - m] - 'a']--;
            window[s[i] - 'a']++;
            if(window == pCount) res.push_back(i - m + 1);
        }
        return res;
    }
};
