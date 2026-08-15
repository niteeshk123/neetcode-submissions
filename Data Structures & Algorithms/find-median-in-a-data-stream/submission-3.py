import heapq
class MedianFinder:

    def __init__(self):
        self.small = []
        self.large = []

    def addNum(self, num: int) -> None:
        if self.small and (-1*num) > self.small[0]:
            heapq.heappush(self.small, -1*num)
        else:
            heapq.heappush(self.large, num)
        
        if len(self.small) > len(self.large)+1:
            temp = heapq.heappop(self.small)
            heapq.heappush(self.large, -1*temp)
        if len(self.large) > len(self.small)+1:
            temp = heapq.heappop(self.large)
            heapq.heappush(self.small, -1*temp)

    def findMedian(self) -> float:
        if len(self.small) > len(self.large):
            return -1*self.small[0]
        elif len(self.large) > len(self.small):
            return self.large[0]
        return (-1*self.small[0]+self.large[0])/2
        