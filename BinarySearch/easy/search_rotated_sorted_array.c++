// good
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (target == nums[i])
            {
                return i;
            }
        }
        return -1;
    }
};
// simple linear

// better/best

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0,high=n-1,mid=0;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            //left sorted 
            else if(nums[low] <= nums[mid]){ // // Check if the left half is sorted
            
                if(nums[low]<=target && target <= nums[mid]){
                    high = mid -1;
                }
                else{
                    low=mid+1;
                }

            }
            //if left is not sorted right will be sorted for sure right sorted 
            else {
                if(nums[mid]<=target && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }

            }
        }


        return -1;
    }
};