class Solution {
public:
    string getHash(string word){
        vector<int> freq(26, 0);
        for(auto c:word){
            freq[c-'a']++;
        }

        string res = "";
        for(auto count:freq){
            res = res + "-" + to_string(count);
        }

        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto word: strs){
            auto hash = getHash(word);
            mp[hash].push_back(word);
        }
        vector<vector<string>> res;

        for(auto it=mp.begin(); it!=mp.end(); it++){
            res.push_back(it->second);
        }

        return res;
    }
};
