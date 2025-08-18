class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> arr(nums.begin(), nums.end());
        return helper(arr);
    }

    bool helper(vector<double>& arr) {
        int n = arr.size();
        // if only one number left, check if it is close to 24
        if (n == 1) {
            return fabs(arr[0] - 24.0) < 1e-6;
        }

        // try all pairs i, j
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

                // build a new vector without i and j
                vector<double> next;
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) next.push_back(arr[k]);
                }

                // try all 4 basic operations on arr[i] and arr[j]
                for (int op = 0; op < 4; ++op) {
                    // addition
                    if (op == 0) next.push_back(arr[i] + arr[j]);
                    // subtraction
                    if (op == 1) next.push_back(arr[i] - arr[j]);
                    // multiplication
                    if (op == 2) next.push_back(arr[i] * arr[j]);
                    // division (avoid division by zero)
                    if (op == 3) {
                        if (fabs(arr[j]) < 1e-6) continue;
                        next.push_back(arr[i] / arr[j]);
                    }

                    if (helper(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
};
