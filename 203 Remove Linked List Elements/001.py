# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} val
    # @return {ListNode}
    def removeElements(self, head, val):
        super = ListNode(0)
        super.next = head
        tail = super
        while tail.next is not None:
            if tail.next.val == val:
                tail.next = tail.next.next
            else:
                tail = tail.next
        return super.next