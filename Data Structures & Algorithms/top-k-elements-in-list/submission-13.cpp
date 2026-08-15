class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto num: nums){
            mp[num]++;
        }

        vector<vector<int>> freq(nums.size()+1);

        for(auto it=mp.begin(); it!=mp.end(); it++){
            freq[it->second].push_back(it->first);
        }

        int cnt = 0;
        vector<int> res;
        for(int i=nums.size(); i>=0; i--){
            for(int j=0; j<freq[i].size(); j++){
                res.push_back(freq[i][j]);
                cnt++;
                if(cnt == k){
                    return res;
                }
            }
        }
        return {};
    }
};
