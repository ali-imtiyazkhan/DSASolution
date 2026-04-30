class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string curr = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            }
            else if (ch == '[') {
                st.push({curr, k});
                curr = "";
                k = 0;
            }
            else if (ch == ']') {
                auto [prev, count] = st.top();
                st.pop();

                string temp = "";
                for (int i = 0; i < count; i++) {
                    temp += curr;
                }

                curr = prev + temp;
            }
            else {
                curr += ch;
            }
        }

        return curr;
    }
};