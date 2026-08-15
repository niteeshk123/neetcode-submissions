class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int len = nums.size();
        for(int i=0;i<len;i++){
            st.insert(nums[i]);
        }
        int res = 0;
        for(int i=0;i<len;i++){
            if(st.find(nums[i])!=st.end() && st.find(nums[i]-1)==st.end()){
                int val = nums[i];
                int count = 0;
                while(st.find(val)!=st.end()){
                    // printf("%d ",val);
                    st.erase(val);
                    count++;
                    val++;
                    
                    
                }
                res=max(res, count);
            }
            printf("\n");
            
        }
        return res;
    }
};
