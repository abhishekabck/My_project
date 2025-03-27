class ListNode:
    def __init__(self, val: int, next = None):
        self.val = val
        self.next = next
    

class LinkedList:
    def __init__(self):
        self.head = None
    
    
    def MergeSortedList(self, List: object):
        # Creating dummy list
        newList = LinkedList()
        dummy = newList.head = ListNode(0)
        
        temp1, temp2 = self.head, List.head
        while temp1 and temp2:
            if temp1.val < temp2.val:
                val = temp1.val
                temp1 = temp1.next
            else:
                val = temp2.val
                temp2 = temp2.next
            dummy.next = ListNode(val)
            dummy = dummy.next
        
        while temp1:
            dummy.next = ListNode(temp1.val)
            dummy = dummy.next
            temp1 = temp1.next
            
        while temp2:
            dummy.next = ListNode(temp2.val)
            dummy = dummy.next
            temp2 = temp2.next
        
        newList.head = newList.head.next
        return newList
    

    def PrintList(self):
        temp = self.head
        while temp:
            print(temp.val, "-> ", end ="")
            temp = temp.next
        print()
    

def MergeTwoSortedArray(array1: list[int], array2: list[int]) -> list[int]:
    i, j = 0, 0
    result = []
    while i < len(array1) and j < len(array2):
        if array1[i] < array2[j]:
            result.append(array1[i])
            i += 1
        else:
            result.append(array2[j])
            j += 1
    while i < len(array1):
        result.append(array1[i])
        i+=1
    
    while j < len(array2):
        result.append(array2[j])
        j += 1
    return result
    

l1 = LinkedList()
l2 = LinkedList()
l1.head = ListNode(23, ListNode(34, ListNode(35, ListNode(53, ListNode(234)))))
l2.head = ListNode(24, ListNode(45, ListNode(58, ListNode(60, ListNode(352)))))

l3 = l1.MergeSortedList(l2)
l3.PrintList()
