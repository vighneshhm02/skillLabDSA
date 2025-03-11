def rearrange_string(s):
    freq = {}
    
    
    for char in s:
        freq[char] = freq.get(char, 0) + 1

  
    max_freq = max(freq.values())
    n = len(s)

   
    if max_freq > (n + 1) // 2:
        return "0"

   
    sorted_chars = sorted(freq.keys(), key=lambda x: -freq[x])

    result = [""] * n
    index = 0

  
    for char in sorted_chars:
        for _ in range(freq[char]):
            result[index] = char
            index += 2
            if index >= n:
                index = 1 
    return "1" 
s = input().strip()
print(rearrange_string(s))
