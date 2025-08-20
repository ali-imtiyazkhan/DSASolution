class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        // Build the frequency map of all words
        unordered_map<string, int> wordFreq;
        for (auto &w : words) {
            wordFreq[w]++;
        }

        // We need to try starting from 0 ... wordLen-1
        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            int right = i;
            int count = 0;
            unordered_map<string, int> windowFreq;

            while (right + wordLen <= (int)s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                // If it's a valid word, update window frequency
                if (wordFreq.count(word)) {
                    windowFreq[word]++;
                    count++;

                    // If we see this word too many times, move left pointer
                    while (windowFreq[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowFreq[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // If we have found all words exactly once, record the index
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Reset the window if the word is not in the list
                    windowFreq.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
