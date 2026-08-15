class Solution:
    def twoSum(self, nums, target):
        map = {}
        res = []
        for num in nums:
            sum = target - num
            if num in map:
                res.append([map[num], num])
            else:
                map[sum] = num
        return res
    
    def uniqu(self, nums):
        res = []
        for num in nums:
            num.sort()
            if num not in res:
                res.append(num)
        return res
    
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []

        for i in range(len(nums)):
            temp = self.twoSum(nums[i+1:], -1*nums[i])
            for temp_res in temp:
                res.append([nums[i]]+temp_res)
        
        return self.uniqu(res)