class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(auto &str: strs){
            res+=str+"]";
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int n = s.length();
        string str = "";
        for(int i=0; i<n; i++){
            if(s[i]==']'){
                res.push_back(str);
                str="";
            } else {
                str+=s[i];
            }
        }

        return res;
    }
};
