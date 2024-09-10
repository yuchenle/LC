# -*- coding: utf-8 -*-
"""
Created on Tue Sep 10 22:40:21 2024

@author: ycle
"""

class Solution:
    def myLog10(self, x:int) -> int :
        ret = 0
        while(x>=10):
            if x/10 >= 1:
                ret += 1
                x = int(x / 10)
                # print(x)
        return ret

    def isPalindrome(self, x: int) -> bool:
        if x > 0 and x < 10:
            return True
        
        if x < 0:
            return False
        
        log_10 = self.myLog10(x)
        numberDigit = int(self.myLog10(x) + 1)
        upperBound = int(numberDigit/2)
        
        # print(numberDigit,upperBound)
        
        ret = True
        
        for i in range(upperBound):
            power_left = int(log_10) - i
            digit_left = int(x/10**power_left) % 10
            
            power_right = i+1
            digit_right = int( (x % 10**power_right) / (10**(power_right - 1)) )
            
            # print(digit_left, digit_right)
            
            if digit_left != digit_right:
                ret = False
        
        return ret

s=Solution()
# print(s.isPalindrome(-121))
# print(s.isPalindrome(10))
print(s.isPalindrome(21112))