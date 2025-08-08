class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result = "";

        // Check sign
        if ((numerator < 0) ^ (denominator < 0))
            result += "-";

        // Convert to long long to avoid overflow (e.g., INT_MIN case)
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // Integer part
        result += to_string(n / d);
        long long remainder = n % d;

        // If no fractional part
        if (remainder == 0) return result;

        result += ".";
        unordered_map<long long, int> remainderIndex;

        while (remainder) {
            if (remainderIndex.count(remainder)) {
                result.insert(remainderIndex[remainder], "(");
                result += ")";
                break;
            }
            remainderIndex[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / d);
            remainder %= d;
        }

        return result;
    }
};
