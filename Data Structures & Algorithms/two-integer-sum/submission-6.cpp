class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashmap;
        int len = nums.size();
        for(int i=0;i<len;i++){
            if(hashmap.find(nums[i])!=hashmap.end()){
                return {hashmap[nums[i]],i};
            }
            hashmap[target-nums[i]] = i;
        }
        return {};
    }
};
