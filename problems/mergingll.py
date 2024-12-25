# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1, list2):
        dummy = ListNode()
        current = dummy
        while list1!=None and list2!=None:
            if list1.val > list2.val:
                current.next = list2
                list2 = list2.next
                current = current.next
            else:
                current.next = list1
                list1 = list1.next
                current = current.next
        while list1 != None:
            current.next = list1
            current = current.next
            list1 = list1.next
        while list2 != None:
            current.next = list2
            current = current.next
            list2 = list2.next
        current.next = None
        return dummy.next

list1 = ListNode(1,ListNode(2, ListNode(3)))
list2 = ListNode(1, ListNode(3, ListNode(4)))

def printll(node):
    while node!=None:
        print(node.val, end = " ")
        node = node.next
    print()
printll(Solution().mergeTwoLists(list1, list2))