class Solution {
public:
    long long solve(vector<int>& Astart, vector<int>& Adur,
                    vector<int>& Bstart, vector<int>& Bdur) {

        int m = Bstart.size();

        vector<pair<int,int>> rides;
        for (int i = 0; i < m; i++) {
            rides.push_back({Bstart[i], Bdur[i]});
        }

        sort(rides.begin(), rides.end());

        vector<int> starts(m);

        vector<long long> prefMinDur(m);
        vector<long long> suffMinFinish(m);

        for (int i = 0; i < m; i++) {
            starts[i] = rides[i].first;

            if (i == 0)
                prefMinDur[i] = rides[i].second;
            else
                prefMinDur[i] = min(prefMinDur[i - 1],
                                    (long long)rides[i].second);
        }

        for (int i = m - 1; i >= 0; i--) {
            long long val = (long long)rides[i].first + rides[i].second;

            if (i == m - 1)
                suffMinFinish[i] = val;
            else
                suffMinFinish[i] = min(suffMinFinish[i + 1], val);
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < (int)Astart.size(); i++) {

            long long endTime = (long long)Astart[i] + Adur[i];

            int pos = upper_bound(starts.begin(), starts.end(), endTime)
                      - starts.begin();

            long long best = LLONG_MAX;

            if (pos > 0) {
                best = min(best,
                           endTime + prefMinDur[pos - 1]);
            }

            if (pos < m) {
                best = min(best,
                           suffMinFinish[pos]);
            }

            ans = min(ans, best);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStart,
                           vector<int>& landDuration,
                           vector<int>& waterStart,
                           vector<int>& waterDuration) {

        long long ans1 =
            solve(landStart, landDuration,
                  waterStart, waterDuration);

        long long ans2 =
            solve(waterStart, waterDuration,
                  landStart, landDuration);

        return (int)min(ans1, ans2);
    }
};