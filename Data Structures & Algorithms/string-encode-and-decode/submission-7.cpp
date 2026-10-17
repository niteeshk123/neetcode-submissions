class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(auto str:strs){
            res = res + to_string(str.length())+"~" +str; 
        }

        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        int j = 0;
        int n = s.length();
        vector<string> res;
        cout << "s = "<<s<<endl;
        while(i<n){
            j = i;
            while(s[j]!='~'){
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            j = j+1;
            res.push_back(s.substr(j, len));
            i = j+len;
        }
        return res;
    }
};
