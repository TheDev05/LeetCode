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
        ListNode *temp = head;
        int count = 0;

        while (temp)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || k == 0 || head->next == NULL)
    return head;

    ListNode *temp = head;

    int length = getLength(head);
    if (k >= length)
        k = k % length;

    int delta = length - k;
    ListNode *newHead = NULL;

    if(k == 0)
     return head;

    int count = 1;
    while (temp->next)
    {
        if (count == delta)
        {
            ListNode *res = temp->next;
            temp->next = NULL;
            temp = res;

            if (newHead == NULL)
                newHead = temp;
        }
        else
            temp = temp->next;

        count++;
    }

    temp->next = head;
    return newHead;
    }
};