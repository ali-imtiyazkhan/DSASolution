class Solution {
public:
    // Helper function to compute the longest window where 
    // we can flip at most k characters to make all == ch
    int maxLen(string &s, int k, char ch) {
        int left = 0, flips = 0, ans = 0;
        
        for(int right = 0; right < s.size(); right++) {
            if(s[right] != ch) flips++;   // this character needs to be flipped
            
            // If flips exceed k, shrink window
            while(flips > k) {
                if(s[left] != ch) flips--;
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        // Try converting everything to 'T'  and  also try converting everything to 'F'
        return max(maxLen(answerKey, k, 'T'), maxLen(answerKey, k, 'F'));
    }
};
