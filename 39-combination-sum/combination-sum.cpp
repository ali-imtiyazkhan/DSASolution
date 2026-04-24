class Solution {
public:
    vector<vector<int>> result;

    void solve(int index, vector<int>& candidates, int target, vector<int>& temp) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        if (index >= candidates.size() || target < 0) {
            return;
        }

        temp.push_back(candidates[index]);
        solve(index, candidates, target - candidates[index], temp);
        temp.pop_back();
        solve(index + 1, candidates, target, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(0, candidates, target, temp);
        return result;
    }
};