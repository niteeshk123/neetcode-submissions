class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(auto num: nums){
            st.insert(num);
        }

        int count = 0;
        for(auto num: st){
            if(st.find(num-1)!=st.end()){
                continue;
            }
            int temp_count = 0;
            int x = num;
            while(st.find(x)!=st.end()){
                temp_count++;
                x=x+1;
            }
            count = max(count, temp_count);
        }

        return count;
    }
};
