from collections import deque 

def reverse_first_k(queue, k):
    if k>len(queue) or k <=0:
        return queue
    
    stack = []

    # step 1
    for i in range(k):
        stack.append(queue.popleft())

    # step 2
    while stack:
        queue.append(stack.pop())

    # step 3
    for i in range(len(queue)-k):
        queue.append(queue.popleft())

    return queue


n=5
k=3 
queue = deque([1,2,3,4,5])

print(reverse_first_k(queue,k))