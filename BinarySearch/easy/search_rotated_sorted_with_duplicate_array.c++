class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //first good approach same the linear seach one
        //as for best 
        int n=nums.size();
        int low=0,high=n-1,mid=0;
        while(low<=high){
            mid= (low+high)/2;
            if(nums[mid]==target){
                return true;
            }
            // checking for the edge case where low mid high is equal in that case just trim the range from low and high
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }

            // checking for if left half is sorted
            else if(nums[low]<= nums[mid]){
                if(nums[low]<=target && target <= nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            // left will must be sorted so going for right
            else{
                if(nums[mid]<=target && target <= nums[high]){
                low=mid+1;
                }
                else{
                high = mid-1;
                }
            }
        }
        return false;
    }
};