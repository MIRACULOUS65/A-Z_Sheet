#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to remove outermost parentheses from every 
    // primitive in a valid parentheses string
    string removeOuterParentheses(string s) {
        // Initialize result string
        string res = "";

        // Initialize balance counter
        int balance = 0;

        // Traverse input string
        for (char c : s) {
            // If opening bracket
            if (c == '(') {
                // Append if not outermost
                if (balance > 0) res += c;
                // Increment balance
                balance++;
            } else { // closing bracket
                // Decrement balance
                balance--;
                // Append if not outermost
                if (balance > 0) res += c;
            }
        }

        // Return result string
        return res;
    }
};

// Driver code
int main() {
    Solution sol;
    string s = "(()())(())";
    cout << sol.removeOuterParentheses(s) << endl; // Output: ()()()
}