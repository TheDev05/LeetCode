/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int index) {
        
    if(head->next == NULL)
    return NULL;
    ListNode *prev = NULL, *next = NULL;

    ListNode *first = head, *last = head;
    int firstIndex = 1, lastIndex = 1;

    while (last)
    {
        if (lastIndex - firstIndex == index)
        {
            if (last->next == NULL)
            {
                prev = first;
                break;
            }

            last = last->next;
            first = first->next;

            lastIndex++;
            firstIndex++;
        }
        else
            lastIndex++,
                last = last->next;
    }

    if(prev == NULL)
        return head->next;

    if (prev->next && prev->next->next)
        next = prev->next->next;

    if (prev && next || prev)
        prev->next = next;
        
    return head;
        
    }
};