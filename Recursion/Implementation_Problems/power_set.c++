#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void func(int ind, int n, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans) {
        // Base case: if the index reaches the length of the array,
        // add the current subset to the answer list
        if (ind == n) {
            ans.push_back(arr);
            return;
        }

        // Recursive case: Exclude the current element and move to the next element
        func(ind + 1, n, nums, arr, ans);

        // Include the current element in the subset and move to the next element
        arr.push_back(nums[ind]);
        func(ind + 1, n, nums, arr, ans);

        // Backtrack: remove the last added element to explore other subsets
        arr.pop_back();
    }

public:
    vector<vector<int>> powerSet(vector<int> &nums) {
        vector<vector<int>> ans;  // List to store all subsets
        vector<int> arr;  // Temporary list to store the current subset
        func(0, nums.size(), nums, arr, ans);  // Start the recursive process
        return ans;  // Return the list of all subsets
    }
};

// Main method to test the code
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.powerSet(nums);
    
    // Print the result
    for (const auto &subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}