# class PriorityQueue(object):
#     def __init__(self):
#         self.queue = []
    
#     def __str__(self):
#         return ' '.join([str(i) for i in self.queue])
    
#     def isEmpty(self):
#         return len(self.queue) == 0
    
#     def insert(self, data):
#         self.queue.append(data)
    
#     def delete(self):
#         try:
#             max_val = 0
#             for i in range(len(self.queue)):
#                 if self.queue[i] > self.queue[max_val]:
#                     max_val = i
#             item = self.queue[max_val]
#             del self.queue[max_val]
#             return item
#         except IndexError:
#             print()
#             exit()

# if __name__ == "__main__":
#     myQueue = PriorityQueue()
#     myQueue.insert(12)
#     myQueue.insert(1)
#     myQueue.insert(43)
#     myQueue.insert(7)
#     while not myQueue.isEmpty():
#         print(myQueue.delete())

import heapq
li = [5, 1, 5, 2, 9, 1, 3]
heapq.heapify(li)

print("The created head is : ", li)
heapq.heappush(li, 42)
print(li)
while True:
    print(heapq.heappop(li))