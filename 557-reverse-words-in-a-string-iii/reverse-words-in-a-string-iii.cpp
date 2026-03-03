class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;

        for (int i = 0; i <= n; i++) {
            
            // When we reach space or end of string
            if (i == n || s[i] == ' ') {
                
                int left = start;
                int right = i - 1;

                // Reverse current word
                while (left < right) {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }

                // Move start to next word
                start = i + 1;
            }
        }

        return s;
    }
};