class Solution {
public:
    string sortVowels(string s) {
        // Helper function to check if a character is a vowel
        auto isVowel = [](char c) {
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
                   c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
        };

        // Step 1: Collect vowels
        vector<char> vowels;
        for (char c : s) {
            if (isVowel(c)) vowels.push_back(c);
        }

        // Step 2: Sort vowels by ASCII value
        sort(vowels.begin(), vowels.end());

        // Step 3: Place back sorted vowels into string
        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[idx++];
            }
        }

        return s;
    }
};
