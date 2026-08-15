class comp{
    public:
    bool operator()(pair<int,int> a, pair<int, int> b){
        return b.first<a.first?true:false;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> min_heap;
        unordered_map<int, int> mp;
        for(auto num:nums){
            mp[num]++;
        }

        for(auto it:mp){
            printf("%d\n", it.second);
            min_heap.push({it.second, it.first});
            if(min_heap.size()> k){
                min_heap.pop();
            }
        }
        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return res;

    }
};
