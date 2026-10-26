class Solution{

    private:
    bool possible(int ind, int k,vector<int>& nums){
        if(k==0){
            return true;
        }
        int n = nums.size();

        if(k<0 || ind==n){
            return false;
        }

        return possible(ind+1,k-nums[ind],nums) || possible(ind+1,k,nums);
    }

    public:
    bool checkSubsequenceSum(vector<int>& nums, int k) {
         //your code goes here
         return possible(0,k,nums);
    }
};