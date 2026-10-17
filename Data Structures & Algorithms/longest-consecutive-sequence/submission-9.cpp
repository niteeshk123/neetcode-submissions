class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(auto num:nums){
            st.insert(num);
        }
        int cnt = 0;
        for(auto num:nums){
            if(st.find(num-1)==st.end()){
                int x = num;
                int temp = 1;
                while(st.find(x+1)!=st.end()){
                    temp++;
                    x = x+1;
                }
                cnt = max(cnt, temp);
            }
        }
        return cnt;
    }
};
