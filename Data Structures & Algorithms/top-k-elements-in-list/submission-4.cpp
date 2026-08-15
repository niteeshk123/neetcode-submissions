class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<vector<int>> pq;
        map<int, int> mp;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto it:mp){
            pq.push({it.second, it.first});
        }

        vector<int> res;
        while(!pq.empty()){
            vector<int> temp = pq.top();
            pq.pop();

            res.push_back(temp[1]);
            if(res.size()==k){
                return res;
            }
        }

        return res;

    }
};
