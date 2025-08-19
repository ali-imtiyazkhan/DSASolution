class Solution {
public:
 bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int count = 0;

        for(int i = 0;i<k;i++){
            if(isVowel(s[i])) count++;
        }

    int ans = count;

    for(int i = k;i<n;i++){
        if(isVowel(s[i-k])) count--;
        if(isVowel(s[i])) count++;

        ans = max(ans,count);
    }

    return ans;
    }
};