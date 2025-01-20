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

ListNode *newNode(ListNode *head1, ListNode *head2, int min)
{
    ListNode *left = head1, *right = head1;
    int leftCount = 0, rightCount = 0;

    ListNode *prev = NULL;
    ListNode *newHead = NULL, *secondHead = head2;

    while (secondHead && left)
    {
        if ((rightCount - leftCount) + 1 == min)
        {
            if (right->next == NULL)
            {
                int sum = secondHead->val + left->val;

                ListNode *inox = new ListNode(sum);
                if (prev == NULL)
                    prev = inox;
                else
                    prev->next = inox;

                if (newHead == NULL)
                    newHead = inox;

                prev = inox;

                secondHead = secondHead->next;
                left = left->next;
            }
            else
            {
                ListNode *newNode = new ListNode(left->val);
                if (prev != NULL)
                    prev->next = newNode;
                prev = newNode;

                if (newHead == NULL)
                    newHead = newNode;

                right = right->next;
                left = left->next;
            }
        }
        else
            right = right->next, rightCount++;
    }

    return newHead;
}

int splitNode(ListNode *head)
{
    if (head == NULL)
        return 0;

    int rem = splitNode(head->next);

    int temp = head->val + rem;
    head->val = temp % 10;

    return temp / 10;
}
 
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        
    int min = 0;
    ListNode *temp1 = head1, *temp2 = head2;

    while (temp1 && temp2)
    {
        min++;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    ListNode *res = NULL;
    if (temp1)
        res = newNode(head1, head2, min);
    else
        res = newNode(head2, head1, min);
    
    int rem = splitNode(res);
    if (rem)
    {
        ListNode *inox = new ListNode(rem);
        inox->next = res;

        res = inox;
    }
        
    return res;
    }
};