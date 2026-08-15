class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq_s(26, 0);
        vector<int> freq_t(26, 0);

        int n = s.length();
        int m = t.length();
        int i=0; 
        int j=0;
        while(i<n || j<m){
            if(i<n){
                freq_s[s[i]-'a']+=1;
                i++;
            }
            if(j<m){
                freq_t[t[j]-'a']+=1;
                j+=1;
            }
        }

        for(int i=0; i<26; i++){
            if(freq_s[i]!=freq_t[i]){
                return false;
            }
        }

        return true;

    }
};
