class Solution {
public:
    vector<int> get_pse(vector<int> &heights){
        int n = heights.size();
        vector<int> res(n, -1);
        stack<int> st;
        for(int i = 0; i<n ;i++){
            while(!st.empty() && (heights[st.top()] >= heights[i])){
                st.pop();
            }

            if(st.empty()){
                st.push(i);
                res[i] = -1;
                continue;
            }

            res[i] = st.top();
            st.push(i);

        }
        // cout <<"PSE = "<<endl;
        // for(auto num:res){
        //     cout<<" "<<num<<" ";
        // }
        // cout<<endl;
        return res;
    }

    vector<int> get_nse(vector<int> &heights){
        int n = heights.size();
        vector<int> res(n, n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
                while(!st.empty() && (heights[st.top()] >= heights[i])){
                st.pop();
            }

            if(st.empty()){
                st.push(i);
                continue;
            }
            // cout<<" top = "<<st.top();
            res[i] = st.top();
            st.push(i);
        }

        // cout <<"NSE = "<<endl;
        // for(auto num:res){
        //     cout<<" "<<num<<" ";
        // }
        // cout<<endl;

        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = get_nse(heights);
        vector<int> pse = get_pse(heights);
        int n = heights.size();
        int res = 0;
        for(int i = 0; i<n; i++){
            int w = nse[i]-pse[i]-1;
            int h = heights[i];
            int area = w*h;
            res = max(res, area);
        }

        return res;
    }
};
