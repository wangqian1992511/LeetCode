# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def addTwoNumbers(self, l1, l2):
        super = tail = ListNode(0)
        c = 0
        while l1 and l2:
            tail.next = ListNode((c + l1.val + l2.val) % 10)
            c = (c + l1.val + l2.val) / 10
            l1 = l1.next
            l2 = l2.next
            tail = tail.next
        while l1:
            tail.next = ListNode((c + l1.val) % 10)
            c = (c + l1.val) / 10
            l1 = l1.next
            tail = tail.next
        while l2:
            tail.next = ListNode((c + l2.val) % 10)
            c = (c + l2.val) / 10
            l2 = l2.next
            tail = tail.next
        if c > 0:
            tail.next = ListNode(1)
        return super.next