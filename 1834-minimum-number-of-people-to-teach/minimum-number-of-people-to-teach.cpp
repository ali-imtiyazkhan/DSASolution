class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size(); // number of people
        // Step 1: convert each person's languages into a set for quick lookup
        vector<unordered_set<int>> know(m + 1);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                know[i + 1].insert(lang); // people are 1-indexed
            }
        }

        // Step 2: find all people involved in "bad" friendships (cannot communicate)
        unordered_set<int> involved;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for (int lang : know[u]) {
                if (know[v].count(lang)) { // common language found
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                involved.insert(u);
                involved.insert(v);
            }
        }

        // If everyone can already talk, no need to teach
        if (involved.empty()) return 0;

        // Step 3: try teaching each language and minimize the number of people to teach
        int ans = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int alreadyKnow = 0;
            for (int person : involved) {
                if (know[person].count(lang)) {
                    alreadyKnow++;
                }
            }
            ans = min(ans, (int)involved.size() - alreadyKnow);
        }

        return ans;
    }
};
