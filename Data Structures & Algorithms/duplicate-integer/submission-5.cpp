class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // unordered_map<int, int> mp;
        set<int> st;
        for(auto num:nums){
            if(st.find(num)!=st.end()){
                return true;
            }
            // mp[num] = 1;
            st.insert(num);
        }

        return false;
    }
};