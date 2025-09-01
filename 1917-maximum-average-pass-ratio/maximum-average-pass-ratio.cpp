class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Lambda to calculate the gain if we add one passing student
        auto gain = [](int p, int t) {
            return (double)(p + 1) / (t + 1) - (double)p / t;
        };

        // Max-heap: {gain, {p, t}}
        priority_queue<pair<double, pair<int,int>>> pq;

        // Initialize heap with all classes
        for (auto &c : classes) {
            int p = c[0], t = c[1];
            pq.push({gain(p, t), {p, t}});
        }

        // Distribute extra students greedily
        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            int p = top.second.first;
            int t = top.second.second;
            p++, t++; // add one passing student
            pq.push({gain(p, t), {p, t}});
        }

        // Compute final average pass ratio
        double sum = 0.0;
        while (!pq.empty()) {
            auto [g, pt] = pq.top(); pq.pop();
            sum += (double)pt.first / pt.second;
        }

        return sum / classes.size();
    }
};
