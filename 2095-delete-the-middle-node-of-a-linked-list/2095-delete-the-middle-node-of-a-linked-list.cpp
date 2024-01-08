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
    ListNode *getMiddle(ListNode *head)
    {
        ListNode *temp = head, *prev = head;
        ListNode *fast = head, *slow = head;

        while (1)
        {
            if (fast->next == NULL)
                return prev;
            if (fast->next->next == NULL)
                return slow;

            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        return NULL;
    }
    
    ListNode* deleteMiddle(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return NULL;
        
    ListNode *midPrev = getMiddle(head);
    ListNode *mid = midPrev->next;
    ListNode *midNext = midPrev->next->next;

    midPrev->next = midNext;
    delete mid;  
        
    return head;
    }
};