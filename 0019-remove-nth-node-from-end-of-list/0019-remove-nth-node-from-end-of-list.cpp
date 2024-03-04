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
int getLength(ListNode *head)
{
    if (head == NULL)
        return 0;

    ListNode *fast = head, *slow = head;
    int count = 1;

    while (fast)
    {
        if (fast->next)
            fast = fast->next->next;
        else
            return count;

        slow = slow->next;

        count += 2;
    }

    return count - 1;
}

    ListNode* removeNthFromEnd(ListNode* head, int k) {
        
    int len = getLength(head);
        
    if(len == k)
        return head->next;
    else 
        k = (len - k) + 1;

    ListNode *temp = head, *prev = NULL;
    while (temp)
    {
        if (--k == 0)
            prev->next = temp->next;

        prev = temp;
        temp = temp->next;        
    }

    return head;        
    }
};