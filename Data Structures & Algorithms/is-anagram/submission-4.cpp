class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> f1(26, 0);
        vector<int> f2(26, 0);
        if(s.length()!=t.length()){
            return false;
        }
        
        for(int i=0; i<s.length(); i++){
            f1[s[i]-'a']++;
            f2[t[i]-'a']++;
        }

        for(int i=0; i<26; i++){
            if(f1[i]!=f2[i]){
                return false;
            }
        }

        return true;
    }
};
