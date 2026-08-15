class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c== 'u'){
            return true;
        } 
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int words_size = words.size();
        vector<int> prefix(words_size, 0);
        // vector<int> suffix(0,words_size);

        for(int i=0; i<words_size; i++){
            string pre_temp = words[i];
            // string suff_temp = words[words_size-i-1];
            if(i!=0){
                prefix[i]=prefix[i-1];
            }

            // if(i!=words_size-1){
            //     suffix[i] = suffix[i+1];
            // }
            
            if(isVowel(pre_temp[0]) && isVowel(pre_temp[pre_temp.length()-1])){
                prefix[i]++;
            }
            // if(suff_temp[0] == suff_temp[suff_temp.length()-1]){
            //     suffix[i]++;
            // }
        }

        // for(int i=0; i<prefix.size(); i++){
        //     printf("%d ", prefix[i]);
        // }

        vector<int> res;
        for(auto q: queries){
            if(q[0]==0){
                res.push_back(prefix[q[1]]);
            } else {
                res.push_back(prefix[q[1]] - prefix[q[0]-1]);
            }
        }

        return res;
    }
};