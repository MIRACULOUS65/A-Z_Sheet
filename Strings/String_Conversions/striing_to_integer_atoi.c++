#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method to convert a string to an integer
    int myAtoi(string input) {
        int i = 0, n = input.size();
        
        // Step 1: Skip leading spaces
        while (i < n && input[i] == ' ') {
            i++;
        }

        // Step 2: Determine the sign
        int sign = 1;
        if (i < n && input[i] == '-') {
            sign = -1;
            i++;
        } else if (i < n && input[i] == '+') {
            i++;
        }

        // Step 3: Parse digits and calculate result
        long long result = 0;
        while (i < n && isdigit(input[i])) {
            result = result * 10 + (input[i] - '0');
            i++;

            // Step 4: Check for overflow
            if (result * sign >= INT_MAX) {
                return INT_MAX;
            }
            if (result * sign <= INT_MIN) {
                return INT_MIN;
            }
        }

        // Step 5: Return the result with sign
        return result * sign;
    }
};

int main() {
    Solution sol;
    
    // Example input
    string input = "42";
    
    // Output the result of converting the string to an integer
    int result = sol.myAtoi(input);
    cout << result << endl;  // Expected output: 42

    return 0;
}