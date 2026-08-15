import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        map = {}
        heap = []
        for num in nums:
            if num in map:
                map[num]+=1
            else:
                map[num]=0
                map[num]+=1
        
        for key in map:
            heapq.heappush(heap, [-1*map[key], key])
        # print(heap)
        res = []
        while(len(heap)):
            res.append(heapq.heappop(heap)[1])
            if(len(res)==k):
                return res
        
        return res
