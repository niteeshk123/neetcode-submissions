class Solution:
    def findMin(self, nums: List[int]) -> int:
        l =0
        n = len(nums)
        r = n-1
        mid = 0
        while(l<=r):
            mid = int(l+((r-l)/2))
            if ((mid!=0 and nums[mid]<=nums[mid-1]) or mid==0) and ((mid!=n-1 and nums[mid]<=nums[mid+1]) or mid==n-1):
                return nums[mid]
            if(nums[mid]<nums[r]):
                r-=1
            else:
                l+=1
        return nums[mid]