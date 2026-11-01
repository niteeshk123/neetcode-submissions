class MinStack {
private:
    stack<long long int> st;
    int minElement;
public:
    MinStack() {
        minElement = -1;
    }
    
    void push(int val) {
        if(st.empty()){
            minElement = val;
            st.push(val);
            return;
        }

        if(val < minElement){
            st.push((2LL*val)-minElement);
            minElement = val;
        } else {
            st.push(val);
        }
        return;
    }
    
    void pop() {
        if(st.empty()){ return ;}
        long long int val = st.top();
        if(val < minElement){
            minElement = (2LL*minElement)-val;
        }
        st.pop();
        return;
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        return st.top()<minElement?minElement:st.top();
    }
    
    int getMin() {
        return minElement;
        
    }
};
