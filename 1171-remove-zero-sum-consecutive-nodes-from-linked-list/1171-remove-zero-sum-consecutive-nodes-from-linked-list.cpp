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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
    std::map<int, ListNode *> data;
    ListNode *temp = head;

    int sum = 0;
    data[sum] = NULL;

    while (temp)
    {
        sum += temp->val;
        if (data.contains(sum))
        {
            ListNode*dash = NULL;
            if(sum == 0) dash = head;
            else dash = data[sum]->next;

            int res = sum;
            while(dash)
            {
                res+=dash->val;
                dash=dash->next;

                if(res == sum) break;
                data.erase(res);

            }

            if(sum == 0) head = dash;
            else if(data[sum]) data[sum]->next = dash;
        }
        else 
            data[sum] = temp;
        
        temp = temp->next;
    }

    return head;
        
    }
};