#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function to find all subsequences with the given target sum
    void func(vector<int>& v, int i, int sum, vector<int>& v2, vector<vector<int>>& ans) {
        // Base case: if the sum is zero, add the current subsequence to the result
        if (sum == 0) {
            ans.push_back(v2);
            return;
        }
        
        // Base case: if the sum becomes negative
        if (sum < 0) {
            return;
        }
        
        // Base case: if no elements are left
        if (i < 0) {
            return;
        }

        // Exclude the current element and move to the next
        func(v, i - 1, sum, v2, ans);
        
        // Include the current element in the subsequence
        v2.push_back(v[i]);
        
        // Recursively call the function with the included element
        func(v, i, sum - v[i], v2, ans);
        
        // Backtrack by removing the last added element
        v2.pop_back();
    }

    // Main function to find all unique combinations of candidates that sum to the target
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        
        // Start the recursive process
        func(candidates, candidates.size() - 1, target, v, ans);
        
        return ans;
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = sol.combinationSum(candidates, target);
    
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}