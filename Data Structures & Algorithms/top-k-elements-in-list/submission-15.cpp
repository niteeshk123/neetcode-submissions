class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto num:nums){
            mp[num]++;
        }
        int n = nums.size();
        vector<vector<int>> freq(n+1);

        for(auto it: mp){
            freq[it.second].push_back(it.first);
        }

        vector<int> res;
        int cnt = 0;
        for(int i=0; i<=n; i++){
            if(freq[n-i].size()!=0){
                for(auto num:freq[n-i]){
                    res.push_back(num);
                    cnt++;
                    if(cnt==k){
                        return res;
                    }
                }
            }
            
        }

        return {};
    }
};
