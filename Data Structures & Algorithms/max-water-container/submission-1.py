class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l_max = heights[0]
        r_max = heights[-1]
        l = 0
        r = len(heights)-1
        water = 0
        while(l<r):
            water = max(water, min(heights[r],heights[l])*(r-l))
            if(heights[r]<heights[l]):
                r-=1
            else:
                l+=1
        return water