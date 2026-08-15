class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        int prod = 1;
        int zero_pos = 0;

        for(int i=0;i<len;i++){
            if(nums[i]!=0){
                prod*=nums[i];
            }
            else{
                zero_pos++;
            }
        }
        if(zero_pos>1){
            for(int i=0;i<len;i++){
                res.push_back(0);
            }
            return res;
        }

        for(int i=0;i<len;i++){
            if(!zero_pos){
                res.push_back(prod/nums[i]);
            }
            else{
                if(nums[i]==0){
                    res.push_back(prod);
                }
                else{
                    res.push_back(0);
                }
            }
        }
        return res;
    }
};
