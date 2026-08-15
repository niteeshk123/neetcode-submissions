class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        my_set = set(nums)
        res = 0
        for num in nums:
            if num-1 in my_set:
                continue
            count = 0
            x = num
            while x in my_set:
                count+=1
                x=x+1
            res = max(res, count)
        return res