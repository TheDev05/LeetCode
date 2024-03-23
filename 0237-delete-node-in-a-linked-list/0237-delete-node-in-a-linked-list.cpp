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
    void deleteNode(ListNode* target) {
        
    ListNode* prev = NULL;
    while (target->next)
    {
        target->val = target->next->val;
        prev = target;
        target = target->next;
    } 
        
    prev->next = NULL;
    delete target;
        
    }
};