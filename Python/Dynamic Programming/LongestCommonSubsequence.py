#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2020-10-03 16:58:03
# @Author  : Sanchit (sanchitahuja205@gmail.com)
# @Link    : link
# @Version : 1.0.0

# Given two string s1 and s2, return the length of their longest common subsequence. For Example, s1 ="abcde" and s2 ="ace", we return 3 since "ace" is the LCS
# This is a classic Dynamic Programming problem which I will solve in Bottom-up fashion

def longest_common_subsequence(s1, s2):
    # declaring an empty array to store my result
    dp_array =  [ [ 0 for _ in range(len(s2)+1) ] for _ in range(len(s1)+1) ]
    for i in range(1, len(s1)+1):
        for j in range(1, len(s2)+1):
            if s1[i-1] == s2[j-1]: # Since the letters are equal we simply add it to our current answer
                dp_array[i][j] = 1 + dp_array[i-1][j-1]
            else :
                # 2 choices, we can either take a char from s1 or s2, which ever choice gives us maximum length of subsequence
                dp_array[i][j] = max(dp_array[i-1][j],dp_array[i][j-1])
    
    return dp_array[-1][-1] #Answer will be stored in the last element of this matrix

if __name__ == "__main__":
    s1 = "abcde"
    s2 = "ace"
    print(longest_common_subsequence(s1,s2))
    s1 = "abc"
    s2 = "abc"
    print(longest_common_subsequence(s1,s2))