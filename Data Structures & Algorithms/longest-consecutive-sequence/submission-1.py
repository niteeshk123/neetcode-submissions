class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        my_set = set()
        for num in nums:
            my_set.add(num)
        
        count = 0
        res = 0
        for num in my_set:
            if num-1 in my_set:
                continue
            count = 1
            # my_set.remove(num)
            k = num+1
            while k in my_set:
                count+=1
                # my_set.remove(k)
                k=k+1
            res = max(res, count)  
        return res