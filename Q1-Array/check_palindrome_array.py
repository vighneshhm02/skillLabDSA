def is_palindrome(n):
    return n == n[::-1]  # String reversal

def all_elements_palindrome():
  
    return all(is_palindrome(num) for num in arr)

arr = input().split()
print(all_elements_palindrome())
