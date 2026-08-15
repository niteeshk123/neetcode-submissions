class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = -1;
        for(int i=0; i<nums.size(); i++){
            max_reach = max(max_reach, i+nums[i]);
            if(max_reach >= nums.size()-1){
                return true;
            }
            if(max_reach <= i){
                return false;
            }
            
        }

        return true;
    }
};
