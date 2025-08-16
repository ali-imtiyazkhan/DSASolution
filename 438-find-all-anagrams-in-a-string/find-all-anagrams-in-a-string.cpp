class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size() < p.size()) return res;

        // frequency count of characters in p
        vector<int> pCount(26, 0);
        // frequency count of current window in s
        vector<int> window(26, 0);

        // fill frequency of p
        for(char c : p) {
            pCount[c - 'a']++;
        }

        int n = s.size();
        int m = p.size();

        // initialize the first window
        for(int i = 0; i < m; i++) {
            window[s[i] - 'a']++;
        }
        // if first window is an anagram
        if(window == pCount) res.push_back(0);

        // slide the window
        for(int i = m; i < n; i++) {
            // remove the character that goes out of the window
            window[s[i - m] - 'a']--;
            // add the new character
            window[s[i] - 'a']++;
            // check if current window is an anagram
            if(window == pCount) res.push_back(i - m + 1);
        }
        return res;
    }
};
