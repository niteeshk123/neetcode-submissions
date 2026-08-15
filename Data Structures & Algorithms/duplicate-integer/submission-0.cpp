class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> map;
        for(int i=0;i<len;i++){
            map[nums[i]]++;
            if(map[nums[i]]>=2){
                return true;
            }
        }
        return false;
    }
};
