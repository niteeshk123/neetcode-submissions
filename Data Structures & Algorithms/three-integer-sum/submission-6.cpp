class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int end, int target){
        int low= start;
        int high = end;
        int sum = 0;
        vector<vector<int>> ans;
        printf("target = %d\n",target);
        while(low<high) {
            sum = nums[low]+nums[high];
            printf("nums[low]=%d nums[high]=%d sum=%d targe=%d\n",nums[low],nums[high],sum,target);
            if(sum>target){
                high--;
            }
            else if(sum<target) {
                low++;
            }
            else {
                ans.push_back({nums[low],nums[high]});
                printf("nums[low]=%d nums[high]=%d\n",nums[low],nums[high]);
                high--;
                while(low<high && nums[low]==nums[low+1]){
                    low++;
                }
                low++;
                
            }

            

        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int len = nums.size();
        vector<vector<int>> ans;
        for(int i=1;i<len;i++){
            if(i-2>=0 && nums[i-1]==nums[i-2]){
                continue;
            }
            vector<vector<int>> res;
            res = twoSum(nums, i, len-1, -nums[i-1]);
            for(int j=0;j<res.size();j++){
                ans.push_back({nums[i-1],res[j][0],res[j][1]});
            }
        }
        return ans;
    }
};
