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
            heapq.heappush(heap, [map[key], key])
            if len(heap)>k:
                heapq.heappop(heap)
        
        return [num for count, num in heap]
        # print(heap)
        
