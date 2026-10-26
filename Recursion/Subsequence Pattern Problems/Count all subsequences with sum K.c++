class Solution {
   private:
    int possible(int ind, int sum, vector<int> &nums) {
        if (sum == 0) return 1;
        if (sum < 0 || ind == nums.size()) return 0;
        return possible(ind + 1, sum - nums[ind], nums) + possible(ind + 1, sum, nums);
    }

   public:
    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        // your code goes here
        return possible(0, k, nums);
    }
};