class Solution {
public:

bool isVowels(char c){
   if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'|| c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;
   else{
    return false;
   }
}
     
    string sortVowels(string s) {

        vector<char> vowels;
        for (char c : s) {
            if (isVowels(c)) vowels.push_back(c);
        }

        sort(vowels.begin(), vowels.end());

        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowels(s[i])) {
                s[i] = vowels[idx++];
            }
        }

        return s;
    }
};
