class Solution {
public:
    string get_key(string s){
        vector<int> freq(26, 0);
        for(auto c: s){
            freq[c-'a']++;
        }

        string key = "";
        for(auto f:freq){
            key = key+"~"+to_string(f);
        }

        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto str:strs){
            // string s = str;
            // sort(s.begin(), s.end());
            mp[get_key(str)].push_back(str);
        }

        vector<vector<string>> res;
        for(auto &it: mp){
            res.push_back(it.second);
        }

        return res;
    }
};
