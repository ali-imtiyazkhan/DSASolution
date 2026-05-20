class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> freqA(n + 1, 0);
        vector<int> freqB(n + 1, 0);

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            freqA[A[i]] = 1;
            freqB[B[i]] = 1;

            int common = 0;

            for (int num = 1; num <= n; num++) {
                if (freqA[num] && freqB[num]) {
                    common++;
                }
            }

            ans.push_back(common);
        }

        return ans;
    }
};