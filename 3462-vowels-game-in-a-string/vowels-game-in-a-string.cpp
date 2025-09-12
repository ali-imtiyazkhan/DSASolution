class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool doesAliceWin(string s) {
        // Alice wins if there is at least one vowel in the string
        for (char c : s) {
            if (isVowel(c)) return true;
        }
        return false;
    }
};
