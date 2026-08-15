class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_key(26, 0);
        vector<int> t_key(26, 0);
        
        for(int i=0; i<s.length(); i++){
            s_key[s[i]-'a']++;
        }

        for(int i=0; i<t.length(); i++){
            t_key[t[i]-'a']++;
        }

        if(s_key == t_key){
            return true;
        }

        return false;
    }
};
