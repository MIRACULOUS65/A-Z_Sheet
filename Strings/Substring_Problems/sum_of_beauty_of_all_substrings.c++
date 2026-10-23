#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the total beauty sum of all substrings
    int beautySum(string s) {
        // Variable to store the total beauty sum
        int totalBeauty = 0;

        // Loop through all possible starting indices
        for (int i = 0; i < s.size(); i++) {
            // Array to store frequency of characters in the current substring
            vector<int> freq(26, 0);

            // Loop through all possible ending indices
            for (int j = i; j < s.size(); j++) {
                // Update frequency of the current character
                freq[s[j] - 'a']++;

                // Find maximum and minimum frequency (excluding zeros)
                int maxFreq = 0, minFreq = INT_MAX;
                for (int f : freq) {
                    if (f > 0) {
                        maxFreq = max(maxFreq, f);
                        minFreq = min(minFreq, f);
                    }
                }

                // Add beauty of this substring (max - min)
                totalBeauty += maxFreq - minFreq;
            }
        }

        // Return total sum
        return totalBeauty;
    }
};

int main() {
    // Create object
    Solution sol;

    // Example 1
    cout << sol.beautySum("xyx") << endl; // Expected 1

    // Example 2
    cout << sol.beautySum("aabcbaa") << endl; // Expected 17
}