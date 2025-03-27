import heapq
from typing import List
from typing import Optional

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = None
    

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        result = ListNode()
        current = result
        pq = []
        # Inserting the elements in the priority queue
        for head, index in enumerate(lists):
            if head:
                heapq.heappush(pq, (head.val, index, head))
        
        # Creating resultant array
        while not pq:
            val, index, head = heapq.heappop(pq)
            if head.next:
                heapq.heappush(pq, (head.next.val, index, head.next))
            current.next = ListNode(val)
            current = current.next
        result = result.next
        return result
