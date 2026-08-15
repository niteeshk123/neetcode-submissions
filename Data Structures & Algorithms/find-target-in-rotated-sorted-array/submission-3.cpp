class Solution {
public:
    int search(vector<int>& nums, int target) {
       int len = nums.size();
       int l = 0;
       int r =  len - 1;
       int mid = 0;
       while(l<=r){
        mid = (l+r)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]>nums[r]){
            /*unsorted array is on rigt*/
            if(nums[l]<=target && nums[mid]>target) {
                r = mid - 1;
            }

            else {
                l = mid+1;
            }
        }
        else{
            if(nums[r]>=target && nums[mid]<target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
       }
       return -1;
    }
};
