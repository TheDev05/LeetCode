/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
    ListNode *fast = head, *slow = head;
    while (fast && slow)
    {
        slow = slow->next;
        if (fast->next)
            fast = fast->next->next;
        else
            return NULL;

        if (fast == slow)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }
        
    return NULL;
    }
};