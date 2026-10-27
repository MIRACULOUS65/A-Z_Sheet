#include <bits/stdc++.h>
using namespace std;


class Solution {
private: 
    // Helper function to calculate subset sums
    void func(int ind, int sum, vector<int> &nums, vector<int> &ans) {
        // Base case: if index reaches the end of the nums vector
        if(ind == nums.size()) {
            // Add the current sum to the ans vector
            ans.push_back(sum);
            return;
        }
        // Recursively include the current element in the sum
        func(ind + 1, sum + nums[ind], nums, ans); 
        // Recursively exclude the current element from the sum
        func(ind + 1, sum, nums, ans); 
    }

public:
    // Function to generate all subset sums
    vector<int> subsetSums(vector<int>& nums) {
        vector<int> ans; 
        // Start the recursion with index 0 and initial sum 0
        func(0, 0, nums, ans);
        return ans;
    }
};

int main() {
    // Sample input vector
    vector<int> nums = {1, 2, 3};
    
    // Create an object of the Solution class
    Solution sol;
    
    // Call the subsetSums function and store the result
    vector<int> result = sol.subsetSums(nums);
    
    // Print the result
    cout << "Subset sums are: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}