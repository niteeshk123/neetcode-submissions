class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int len = nums.size();
        vector<int> res;
        for(int i=0;i<len;i++){
            if(map.find(nums[i])!=map.end()){
                printf("%d-%d=%d nums[%d] ",target, nums[i],target-nums[i], i);
                printf("map = %d \n", map[nums[i]]);
                res.push_back(map[nums[i]]);
                res.push_back(i);
                break;
            }
            else{
                printf("%d. %d\n", target-nums[i],i);
                map[target-nums[i]]=i;
            }
        }
        return res;
    }
};
