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
        
    std::map<int, ListNode *> data;
    ListNode *temp = head;

    int count = 1;
    while (temp)
    {
        data[count] = temp;

        temp = temp->next;
        count++;
    }

    int size = count - 1;
    ListNode *prev = NULL;
    ListNode *next = NULL;

    if(data.contains(size - index))
        prev = data[size - index];

    if (auto it = (size - index) + 2; data.contains(it))
        next = data[it];

    if(prev && next || prev)
       prev->next = next;
    else if(next)
       head = head->next;

    return head;
        
    }
};