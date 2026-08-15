class Solution {
public:
    int recursion(vector<int> &nums, int start, int end, int len){
        if(end == start){
            return nums[end];
        }
        int mid = start+ (end-start)/2;
        if(nums[mid]<nums[end]){
            return recursion(nums, start,mid, len);
        }
        return recursion(nums, mid+1, end, len);
    
    }
    int findMin(vector<int> &nums) {
        return recursion(nums, 0, nums.size()-1, nums.size());
    }
};
