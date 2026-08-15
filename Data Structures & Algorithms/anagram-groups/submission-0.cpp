class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        int len = strs.size();
        for(int i=0;i<len;i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            map[temp].push_back(strs[i]);

        }

        for(auto it=map.begin();it!=map.end();it++){
            res.push_back(it->second);
        }
        return res;
    }
};
