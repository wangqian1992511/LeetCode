001.cpp (123ms):

Judgement of palindrome is one of the most fundamental problems. Obviously, a negative number can never be a palindrome. To avoid overflow, we cannot simply reverse the whole number. But we should reverse only the least significant half of all the digits of the original number. Notice that if the total digits is odd, we can ignore the digit in the middle. Since the input is at most 10 digits, we can say that the time complexity is O(1).
