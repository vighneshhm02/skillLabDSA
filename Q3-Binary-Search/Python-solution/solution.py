def can_place_cows(stalls, cows, min_dist):
    # Placing the first cow 
    count = 1  
    last_pos = stalls[0]

    for i in range(1, len(stalls)):
        if stalls[i] - last_pos >= min_dist:
            count += 1
             # Place the cow here
            last_pos = stalls[i] 
            if count == cows:
                return True
    return False

def aggressive_cows(stalls, cows):
    stalls.sort()  
     # Possible distance range
    low, high = 1, stalls[-1] - stalls[0] 
    best = 0

    while low <= high:
        mid = (low + high) // 2
        if can_place_cows(stalls, cows, mid):
            best = mid 
            low = mid + 1
        else:
            high = mid - 1

    return best



stalls = [1, 2, 8, 4, 9]
cows = 3
print(aggressive_cows(stalls, cows))
