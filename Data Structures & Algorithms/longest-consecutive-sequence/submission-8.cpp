class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto num:nums){
            st.insert(num);
        }

        int cnt = 0;
        for(auto num:nums){
            if(st.find(num-1)!=st.end()){
                continue;
            }
            int temp = 0;
            int x = num;
            while(st.find(x)!=st.end()){
                x = x+1;
                temp++;
            }
            cnt = max(cnt, temp);
        }

        return cnt;
    }
};
