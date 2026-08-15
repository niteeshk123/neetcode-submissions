class Solution {
public:
    string hash(string &s){
        vector<int> freq(26, 0);
        for(auto c: s){
            freq[c-'a']++;
        }

        string res="";
        for(int i=0; i<26; i++){
            res = res+to_string(freq[i])+"#";
        }

        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto str: strs){
            mp[hash(str)].push_back(str);
        }

        vector<vector<string>> res;

        for(auto it: mp){
            res.push_back(it.second);
        }

        return res;
    }
};
