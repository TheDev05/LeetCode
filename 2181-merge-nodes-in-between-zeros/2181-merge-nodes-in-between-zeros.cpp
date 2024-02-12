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
    ListNode* mergeNodes(ListNode* head) {
        
    int sum = 0;
    ListNode *temp = head->next;

    ListNode *newHead = NULL;
    ListNode *pointer = newHead;

    while (temp)
    {
        if (temp->val)
            sum += temp->val;
        else
        {
            if (newHead == NULL)
                newHead = new ListNode(sum),
                pointer = newHead;
            else
                pointer->next = new ListNode(sum),
                pointer = pointer->next;

            sum = 0;
        }

        temp = temp->next;
    } 
    
    return newHead;
        
    }
};