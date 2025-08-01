class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
   
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for (const auto& interval : intervals) {
            // If merged is empty OR no overlap with the last interval
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval); // Add new interval
            } else {
                // Overlap: update the end time of the last interval
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};
