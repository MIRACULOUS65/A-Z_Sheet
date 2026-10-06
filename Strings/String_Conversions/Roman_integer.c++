#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to convert roman numeral into an integer
    int romanToInt(string s) {
        // Mapping Roman symbols to their integer values
        unordered_map<char, int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        
        // Result variable
        int total = 0;

        // Traverse the string
        for(int i = 0; i < s.size(); i++) {
            // If next value is larger, subtract current value
            if(i + 1 < s.size() && mp[s[i]] < mp[s[i+1]]) {
                total -= mp[s[i]];
            }
            // Otherwise add current value
            else {
                total += mp[s[i]];
            }
        }
        return total;
    }
};

int main() {
    Solution sol;
    cout << sol.romanToInt("MCMXCIV");
}