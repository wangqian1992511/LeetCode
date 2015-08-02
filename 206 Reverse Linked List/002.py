# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def reverseList(self, head):
        ans = None
        while head is not None:
            tmp = head.next
            head.next = ans
            ans = head
            head = tmp
        return ans