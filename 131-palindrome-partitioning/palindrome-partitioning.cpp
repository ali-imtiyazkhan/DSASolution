class Solution {
public:
    vector<vector<string>> result;

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    void solve(int start, string &s, vector<string> &temp) {

        if (start == s.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = start; i < s.size(); i++) {
       
            if (isPalindrome(s, start, i)) {
                temp.push_back(s.substr(start, i - start + 1));
                solve(i + 1, s, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(0, s, temp);
        return result;
    }
};