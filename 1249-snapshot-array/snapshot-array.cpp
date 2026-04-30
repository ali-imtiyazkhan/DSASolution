class SnapshotArray {
public:
    int snapId;
    vector<vector<pair<int,int>>> arr;

    SnapshotArray(int length) {
        snapId = 0;
        arr.resize(length);
        
        for(int i = 0; i < length; i++) {
            arr[i].push_back({0, 0});
        }
    }
    
    void set(int index, int val) {
        arr[index].push_back({snapId, val});
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto &vec = arr[index];
        
        int l = 0, r = vec.size() - 1;
        int ans = 0;
        
        while(l <= r) {
            int mid = (l + r) / 2;
            
            if(vec[mid].first <= snap_id) {
                ans = vec[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return ans;
    }
};