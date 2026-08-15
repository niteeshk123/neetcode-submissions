# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq
class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        # i = 0
        for i, node in enumerate(lists):
            heapq.heappush(heap, [node.val, i, node])
        
        dummy = ListNode()
        cur = dummy
        i = len(lists)
        while(len(heap)>0):
            cur.next = heapq.heappop(heap)[2]
            cur = cur.next
            if cur.next:
                heapq.heappush(heap, [cur.next.val, i, cur.next])
                i+=1
            cur.next = None
        
        return dummy.next