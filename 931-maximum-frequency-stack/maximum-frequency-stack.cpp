class FreqStack {
public:
    unordered_map<int, int> freq;              // element -> frequency
    unordered_map<int, stack<int>> group;      // frequency -> stack of elements
    int maxFreq = 0;

    FreqStack() {}

    void push(int val) {
        // update frequency
        int f = ++freq[val];

        // update max frequency
        if (f > maxFreq) maxFreq = f;

        // push val into its frequency group
        group[f].push(val);
    }

    int pop() {
        // get the most frequent element
        int val = group[maxFreq].top();
        group[maxFreq].pop();

        // decrease its frequency
        freq[val]--;

        // if no elements left at this frequency, decrease maxFreq
        if (group[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};
