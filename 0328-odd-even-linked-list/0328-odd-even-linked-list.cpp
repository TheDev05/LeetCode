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
    ListNode* oddEvenList(ListNode* head) {
    ListNode *temp = head;

    ListNode *odd = new ListNode(-1);
    ListNode *even = new ListNode(-1);

    ListNode *pointer2odd = odd;
    ListNode *pointer2even = even;

    int index = 1;
    while (temp)
    {
        if (index & 1)
        {
            ListNode *newNode = new ListNode(temp->val);
            pointer2odd->next = newNode;
            pointer2odd = newNode;
        }
        else
        {
            ListNode *newNode = new ListNode(temp->val);
            pointer2even->next = newNode;
            pointer2even = newNode;
        }

        index++;
        temp = temp->next;
    }

    if (even)
        pointer2odd->next = even->next;
        
    head = odd->next;
    return head;
    }
};