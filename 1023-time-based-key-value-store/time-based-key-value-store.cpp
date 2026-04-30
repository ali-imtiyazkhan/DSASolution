class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        
        auto &vec = mp[key];
        
        int left = 0, right = vec.size() - 1;
        string ans = "";
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            if(vec[mid].first <= timestamp) {
                ans = vec[mid].second; // valid candidate
                left = mid + 1;        // try to find closer
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};