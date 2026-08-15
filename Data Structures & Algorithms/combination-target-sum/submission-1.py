class Solution:
    def __init__(self):
        self.res=[]
        self.sum=[]
    def Utility(self, nums, target, start):
        if target==0:
            self.res.append(self.sum.copy())
            return
        elif target<0:
            return
        n = len(nums)
        for i in range(start, n):
            self.sum.append(nums[i])
            self.Utility(nums, target-nums[i], i)
            self.sum.pop(-1)
        
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        self.Utility(nums, target, 0)
        return self.res