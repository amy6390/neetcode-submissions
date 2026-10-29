# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        curr_group_head = head
        head_changed = False
        prev_group_end = None
        while curr_group_head != None:
            curr_group_end = curr_group_head
            group_too_small = False
            for i in range(k - 1):
                curr_group_end = curr_group_end.next
                if curr_group_end == None:
                    group_too_small = True
                    break
            if group_too_small:
                break
            
            #reversing the k nodes
            prev = curr_group_head
            curr = curr_group_head.next
            next_group_start = curr_group_end.next
            for i in range(k - 1):
                tmp = curr.next
                curr.next = prev

                prev = curr
                curr = tmp
            if not head_changed:
                head = curr_group_end
                head_changed = True
            if prev_group_end is not None:
                prev_group_end.next = curr_group_end
            prev_group_end = curr_group_head
            curr_group_head.next = next_group_start
            curr_group_head = curr_group_head.next

        return head
        