class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hashmap;
        int n = strs.size();
        for(int i=0; i<n; i++){
            string str = strs[i];
            sort(str.begin(), str.end());
            hashmap[str].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for(auto &it: hashmap){
            res.push_back(it.second);
        }

        return res;
    }
};
