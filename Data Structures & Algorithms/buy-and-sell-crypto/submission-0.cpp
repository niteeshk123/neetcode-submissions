class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int mini = INT_MAX;
        int res = INT_MIN;
        for(int i=0;i<len;i++){
            res = max(res, prices[i]-mini);
            mini = min(mini, prices[i]);
            
        }
        if(res<0){
            return 0;
        }
        return res;
        
    }
};
