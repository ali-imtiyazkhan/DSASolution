class SmallestInfiniteSet {
public:
    int curr;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> st;

    SmallestInfiniteSet() {
        curr = 1;
    }

    int popSmallest() {
        if (!pq.empty()) {
            int val = pq.top();
            pq.pop();
            st.erase(val);
            return val;
        }
        return curr++;
    }

    void addBack(int num) {
        if (num < curr && st.find(num) == st.end()) {
            pq.push(num);
            st.insert(num);
        }
    }
};