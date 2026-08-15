class Solution {
public:
    bool isSymbol(string c){
        if(c=="+" || c=="-" || c == "*" || c== "/"){
            return true;
        }
        return false;
    }

    int doArithmetic(int a, int b, string c){
        if(c=="+"){
            return a+b;
        }
        else if(c=="-"){
            return a-b;
        }
        else if(c=="*"){
            return a*b;
        }
        else if(c=="/"){
            return a/b;
            
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size(); 
        for(int i = 0; i< n; i++){
            if(isSymbol(tokens[i])){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(doArithmetic(b, a, tokens[i]));
            } else{
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};
