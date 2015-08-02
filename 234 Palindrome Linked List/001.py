# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {boolean}
    def isPalindrome(self, head):
        n = self.calcLen(head)
        other = None
        for i in range(n >> 1):
            t = head.next
            head.next = other
            other = head
            head = t
        if n & 1 == 1:
            head = head.next
        for i in range(n >> 1):
            if other.val != head.val:
                return False
            else:
                other = other.next
                head = head.next
        return True
    def calcLen(self, head):
        n = 0
        while head is not None:
            n += 1
            head = head.next
        return n