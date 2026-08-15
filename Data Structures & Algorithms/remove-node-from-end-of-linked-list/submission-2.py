# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        first = head
        second = head
        k = n
        if n==1 and first.next is None:
            return None
        while(k):
            second = second.next
            k-=1
            if second is None:
                second = head
        
        while second.next:
            first = first.next
            second = second.next
        
        if first.next is None:
            return head.next
        
        first.next = first.next.next
        return head