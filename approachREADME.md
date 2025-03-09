# Rearrange String & Check Palindromes in an Array

## Problem 1: Rearrange Characters in a String
### **Problem Statement**
Given a string with repeated characters, rearrange the characters such that no two adjacent characters are the same. If it's not possible, return `"0"`, otherwise return `"1"`.

### **Approach**
1. **Count character frequencies** in the string.
2. **Check feasibility**: If the most frequent character appears more than `(n+1)/2` times, it's impossible.
3. **Sort characters** by frequency and place them in even positions first.
4. **Fill remaining characters** in odd positions.
5. **Return "1" if successful, else "0".**

---

## Problem 2: Check If All Array Elements Are Palindromes
### **Problem Statement**
Given an array of positive integers, return `1` if all elements are palindromes; otherwise, return `0`.

### **Approach**
1. **Convert numbers to strings** and check if they read the same backward.
2. **Iterate through the array**, verifying each number.
3. **Return `1` if all numbers are palindromes**, otherwise return `0`.
