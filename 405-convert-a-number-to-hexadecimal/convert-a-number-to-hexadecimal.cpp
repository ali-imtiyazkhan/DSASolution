class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";

        unsigned int n = num;
        string result = "";
        string hex = "0123456789abcdef";

        while(n > 0) {
            int digit = n & 15;
            result = hex[digit] + result;
            n >>= 4;    
        }

        return result;
    }
};