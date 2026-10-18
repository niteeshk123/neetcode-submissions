class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_till_now = INT_MAX;
        int res = 0;
        for(auto price:prices){
            res = max(res,price-min_till_now);
            min_till_now = min(min_till_now, price);
        }

        return res;
    }
};
