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
    std::pair<ListNode *, ListNode *> reverseNode(ListNode *start, ListNode *end)
    {
        ListNode *temp = start;
        ListNode *prev = NULL;

        while (temp)
        {
            ListNode *res = temp->next;
            temp->next = prev;

            prev = temp;
            temp = res;

            if (prev == end)
                break;
        }

        return {prev, start};
    }
    
    ListNode* reverseKGroup(ListNode* head, int key) {
    ListNode *temp = head;

    ListNode *start = head;
    std::pair<ListNode *, ListNode *> prev = {NULL, NULL};
    int count = 1;

    ListNode *newHead = NULL;

    while (temp)
    {
        if (count == key)
        {
            ListNode *res = temp->next;
            std::pair<ListNode *, ListNode *> inox = reverseNode(start, temp);

            if (newHead == NULL)
                newHead = inox.first;

            if (prev.first && prev.second)
                prev.second->next = inox.first;

            prev = inox;

            temp = res;
            start = temp;

            count = 1;
        }
        else
        {
            temp = temp->next;
            count++;
        }
    }

    if (start)
        prev.second->next = start;
    return newHead;
    }
};