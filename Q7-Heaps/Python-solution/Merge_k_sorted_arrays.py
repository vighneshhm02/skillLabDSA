import heapq
def mergeK(arr, k):
    res = []
    
    h = []

    for i in range(len(arr)):
        heapq.heappush(h, (arr[i][0], i, 0))

    while h:
        val, row, col = heapq.heappop(h)
        res.append(val)
        if col+1 < len(arr[row]):
            heapq.heappush(h, (arr[row][col+1], row, col+1))
    return res  
