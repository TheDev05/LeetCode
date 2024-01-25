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
    ListNode *createLL(std::vector<int> &num)
    {
        ListNode *head = new ListNode(num[0]);
        ListNode *pointer = head;

        for (int i = 1; i < num.size(); i++)
        {
            ListNode *temp = new ListNode(num[i]);
            pointer->next = temp;
            pointer = temp;
        }

        return head;
    }

    int getGcd(int a, int b)
    {
        if (b == 0)
            return a;

        return getGcd(b, a % b);
    }

    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
    ListNode *temp = head;
    ListNode *curr = head, *prev = NULL;

    while (curr)
    {
        if (prev)
        {
            int gcd = getGcd(prev->val, curr->val);

            ListNode *newNode = new ListNode(gcd);
            prev->next = newNode;

            newNode->next = curr;
        }

        prev = curr;
        curr = curr->next;
    }   
        
    return head;
    }
};