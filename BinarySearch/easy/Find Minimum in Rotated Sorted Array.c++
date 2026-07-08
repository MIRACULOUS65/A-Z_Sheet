#include <algorithm>
#include <climits>

class Solution {
public:
    int findMin(vector<int>& nums) {
        //FIRST APPROACH IS LINEAR SEARCH
        int low=0,high=nums.size()-1,mid=0,ans=INT_MAX;
        while(low<=high){
            mid = (low+high)/2;
            //suppose the whole thing is already sorted
            if(nums[low]<=nums[high]){
                ans = min (ans,nums[low]);
            }
            if(nums[low]<=nums[mid]){
                //means sorted left pick min then ignore 
                ans= min(ans,nums[low]);
                low=mid+1;
            }
            else{
                //means right sorted
                ans= min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};


// as for good approach use our good ol linear search