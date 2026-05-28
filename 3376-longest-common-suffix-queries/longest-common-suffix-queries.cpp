class Solution {
public:

    struct Node {
        int child[26];
        int idx;
        int len;

        Node() {
            memset(child, -1, sizeof(child));
            idx = -1;
            len = INT_MAX;
        }
    };

    vector<Node> trie;

    Solution() {
        trie.push_back(Node()); // root
    }

    void insert(string &word, int index) {

        int n = word.size();
        int node = 0;

        if (n < trie[node].len) {
            trie[node].len = n;
            trie[node].idx = index;
        }

        for (int i = n - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].child[c];

            if (n < trie[node].len) {
                trie[node].len = n;
                trie[node].idx = index;
            }
        }
    }

    int search(string &query) {

        int node = 0;

        for (int i = query.size() - 1; i >= 0; i--) {

            int c = query[i] - 'a';

            if (trie[node].child[c] == -1) {
                break;
            }

            node = trie[node].child[c];
        }

        return trie[node].idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        int smallestIdx = 0;

        for (int i = 1; i < wordsContainer.size(); i++) {
            if (wordsContainer[i].size() <
                wordsContainer[smallestIdx].size()) {
                smallestIdx = i;
            }
        }

        trie[0].idx = smallestIdx;
        trie[0].len = wordsContainer[smallestIdx].size();

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i);
        }

        vector<int> ans;

        for (auto &q : wordsQuery) {
            ans.push_back(search(q));
        }

        return ans;
    }
};