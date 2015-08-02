# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def reverseList(self, head):
        head, tail = self.helper(head)
        return head
    def helper(self, head):
        if head is None or head.next is None:
            return head, head
        newHead, oldTail = self.helper(head.next)
        oldTail.next = head
        head.next = None
        return newHead, head