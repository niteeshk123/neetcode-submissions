class Solution {
public:
    void utility(vector<int> &nums, int start, int target, vector<int> &sum, vector<vector<int>> &res){
        if(target<0){
            return;
        }
        if(target==0){
            res.push_back(sum);
        }

        for(int i=start;i<nums.size();i++){
            sum.push_back(nums[i]);
            utility(nums,i,target-nums[i], sum, res);
            sum.pop_back();
        }
        
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sum;
        vector<vector<int>> res;
        utility(nums,0,target,sum,res);
        return res;
    }
};
