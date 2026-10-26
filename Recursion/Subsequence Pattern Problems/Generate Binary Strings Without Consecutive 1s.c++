#include <bits/stdc++.h>
using namespace std;

// Solution class
class Solution {
public:
    vector<string> result;

    // Helper function to generate strings
    void backtrack(string s, int n, char prev) {
        // If string reaches length n, add to result
        if (s.length() == n) {
            result.push_back(s);
            return;
        }
        // Add '0' and recurse
        backtrack(s + "0", n, '0');
        // Add '1' only if previous char is not '1'
        if (prev != '1') {
            backtrack(s + "1", n, '1');
        }
    }

    // Main function
    vector<string> generateBinaryStrings(int n) {
        result.clear();
        backtrack("", n, '0');
        return result;
    }
};

// Driver code
int main() {
    Solution sol;
    int n = 3;
    vector<string> res = sol.generateBinaryStrings(n);
    for (auto str : res) {
        cout << str << " ";
    }
    cout << endl;
}