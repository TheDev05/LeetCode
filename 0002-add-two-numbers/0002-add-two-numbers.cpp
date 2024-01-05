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
    ListNode* addTwoNumbers(ListNode* LL1, ListNode* LL2) {
        
    ListNode *temp1 = LL1;
    ListNode *temp2 = LL2;

    ListNode *head = NULL;
    ListNode *pointer = head;

    int carry = 0;
    while (temp1 || temp2)
    {
        int val1 = 0, val2 = 0;
        if (temp1)
            val1 = temp1->val,
            temp1 = temp1->next;
        if (temp2)
            val2 = temp2->val,
            temp2 = temp2->next;

        int sum = val1 + val2 + carry;
        int newValue = sum % 10;
        carry = sum / 10;

        ListNode *temp = new ListNode(newValue);
        if (head == NULL)
            head = temp;
        else
            pointer->next = temp;

        pointer = temp;
    }

    while (carry)
    {
        int res = carry % 10;

        ListNode *temp = new ListNode(res);
        pointer->next = temp;
        pointer = temp;

        carry = carry / 10;
    }
        
    return head;
    }
};