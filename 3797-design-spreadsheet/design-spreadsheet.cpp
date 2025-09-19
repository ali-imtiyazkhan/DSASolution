#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
    int n;
    unordered_map<string, string> formulas; // store formulas including "="
    unordered_map<string, int> values;      // store evaluated values

public:
    Spreadsheet(int rows) {
        n = rows;
    }

    void setCell(string cell, int value) {
        values[cell] = value;
        formulas.erase(cell); // remove formula if any
    }

    void setCell(string cell, string formula) {
        formulas[cell] = formula;
        values.erase(cell); // remove previous value
    }

    void resetCell(string cell) {
        formulas.erase(cell);
        values.erase(cell);
    }

    int getValue(string formula) {
        if (formula.empty()) return 0;

        if (formula[0] == '=') {
            return evaluateExpression(formula.substr(1));
        } else if (values.count(formula)) {
            return values[formula];
        } else if (isdigit(formula[0]) || (formula[0] == '-' && formula.size() > 1)) {
            return stoi(formula); // direct number
        } else if (formulas.count(formula)) {
            return evaluateExpression(formulas[formula].substr(1));
        }
        return 0; // empty cell
    }

private:
    int evaluateExpression(const string &expr) {
        int sum = 0;
        string token;
        for (char ch : expr + '+') { // append '+' to handle last token
            if (ch == '+') {
                if (!token.empty()) {
                    sum += getValue(token);
                    token.clear();
                }
            } else {
                token.push_back(ch);
            }
        }
        return sum;
    }
};
