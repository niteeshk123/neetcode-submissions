class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res=0
        min_till_now=10e9
        for price in prices:
            res = max(res, price-min_till_now)
            min_till_now = min(min_till_now, price)
        return res