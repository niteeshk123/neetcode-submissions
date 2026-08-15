class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        l = []
        for num in nums:
            if num in l:
                return True
            l.append(num)
        return False