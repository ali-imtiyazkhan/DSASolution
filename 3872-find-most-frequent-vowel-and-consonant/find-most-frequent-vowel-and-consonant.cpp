class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxFreqSum(string s) {
        vector<int> count(26, 0);
        int maxVowel = 0;
        int maxConsonant = 0;

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                count[c - 'a']++;
            }
        }

        // Find max vowel count
        string vowels = "aeiou";
        for (char v : vowels) {
            maxVowel = max(maxVowel, count[v - 'a']);
        }

        // Find max consonant count
        for (char c = 'a'; c <= 'z'; c++) {
            if (!isVowel(c)) {
                maxConsonant = max(maxConsonant, count[c - 'a']);
            }
        }

        return maxVowel + maxConsonant;
    }
};
